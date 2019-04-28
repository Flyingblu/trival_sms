#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <iomanip>
#include "json.h"
#include <fstream>
#define DATA_PATH "/home/flyingblu/data.json"

using namespace std;

void MainWindow::read_data(string path) {
    ifstream json_file(path);
    nlohmann::json j;
    try {
        json_file >> j;
        json_file.close();
    } catch (nlohmann::detail::parse_error& error) {
        cerr << error.what() << endl;
        cerr << "Overwriting or creating the file..." << endl;
        return;
    }
    for (auto i = j.begin();i != j.end(); i++) {
        string first = (*i)["first_name"].get<string>();
        string last = (*i)["last_name"].get<string>();
        string gender = (*i)["gender"].get<string>();
        string age = (*i)["age"].get<string>();
        string stu_id = (*i)["stu_id"].get<string>();
        auto new_stu = Data::Student(QString::fromStdString(first), QString::fromStdString(last), stoi(gender), stoi(age), QString::fromStdString(stu_id));
        this->students.push_back(new_stu);
        ui->listWidget->addItem(new_stu.get_name());
    }
}

void MainWindow::write_data(string path) {
    ofstream json_file(path);
    nlohmann::json j;
    for(unsigned long i = 0; i < this->students.size(); i++) {
        j[to_string(i)]["first_name"] = students[i].first_name.toStdString();
        j[to_string(i)]["last_name"] = students[i].last_name.toStdString();
        j[to_string(i)]["gender"] = to_string(students[i].gender);
        j[to_string(i)]["age"] = to_string(students[i].age);
        j[to_string(i)]["stu_id"] = students[i].stu_id.toStdString();
    }
    json_file << setw(4) << j;
    json_file.close();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    read_data(DATA_PATH);
    // initialize the gender combo box.
    ui->gender_cb->addItem("Set gender...");
    ui->gender_cb->addItem("Male");
    ui->gender_cb->addItem("Female");
    ui->gender_cb->addItem("Other");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clear_formdata() {
    ui->add_pb->setText("Add");
    ui->first_name_le->clear();
    ui->last_name_le->clear();
    ui->gender_cb->setCurrentIndex(0);
    ui->age_le->clear();
    ui->stu_id_le->clear();
}

bool is_integer(QString input) {
    if(input.size() == 0)
        return false;
    for (int i = 0; i < input.size(); i ++) {
        if(input[i] > '9' || input[i] < '0')
            return false;
    }
    return true;
}

bool is_character(QString input) {
    if(input.size() == 0)
        return false;
    for (int i = 0; i < input.size(); i ++) {
        if((input[i] > 'z' || input[i] < 'a') && (input[i] > 'Z' || input[i] < 'A'))
            return false;
    }
    return true;
}

bool is_char_or_int(QString input) {
    if(input.size() == 0)
        return false;
    for (int i = 0; i < input.size(); i ++) {
        if((input[i] > 'z' || input[i] < 'a') && (input[i] > 'Z' || input[i] < 'A') && (input[i] < '0' || input[i] > '9'))
            return false;
    }
    return true;
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    if(currentRow < 0) {
        this->clear_formdata();
        return;
    }
    auto current_stu = students[currentRow];
    ui->first_name_le->setText(current_stu.first_name);
    ui->last_name_le->setText(current_stu.last_name);
    ui->gender_cb->setCurrentIndex(current_stu.gender);
    ui->age_le->setText(QString::number(current_stu.age));
    ui->stu_id_le->setText(current_stu.stu_id);
    ui->add_pb->setText("Edit");
}

void MainWindow::on_add_pb_clicked()
{
    QString first = ui->first_name_le->text();
    QString last = ui->last_name_le->text();
    bool abort = false;
    if(!is_character(first)) {
        abort = true;
        ui->first_name_warning->setStyleSheet("QLabel {color : red; }");
        ui->first_name_warning->setText("Should only contain char");
    }
    if(!is_character(last)) {
        abort = true;
        ui->last_name_warning->setStyleSheet("QLabel {color : red; }");
        ui->last_name_warning->setText("Should only contain char");
    }
    if(!is_integer(ui->age_le->text())) {
        abort = true;
        ui->age_warning->setStyleSheet("QLabel {color : red; }");
        ui->age_warning->setText("Should only contain int");
    }
    if(!is_char_or_int(ui->stu_id_le->text())) {
        abort = true;
        ui->stu_id_warning->setStyleSheet("QLabel {color : red; }");
        ui->stu_id_warning->setText("Should only contain int or char");
    }
    if(abort)
        return;
    if(ui->add_pb->text() == QString("Add")) {
        Data::Student new_stu = Data::Student(first, last, ui->gender_cb->currentIndex(), ui->age_le->text().toInt(), ui->stu_id_le->text());
        this->clear_formdata();
        this->students.push_back(new_stu);
        ui->listWidget->addItem(new_stu.get_name());
    } else if(ui->add_pb->text() == QString("Edit")) {
        int index = ui->listWidget->currentRow();
        Data::Student *curr_stu = &this->students[index];
        curr_stu->first_name = first;
        curr_stu->last_name = last;
        curr_stu->gender = ui->gender_cb->currentIndex();
        curr_stu->age = ui->age_le->text().toInt();
        curr_stu->stu_id = ui->stu_id_le->text();
        ui->listWidget->currentItem()->setText(curr_stu->get_name());
    }
    this->write_data(DATA_PATH);
}

void MainWindow::on_del_pb_clicked()
{
    if(!this->students.size())
        return;
    int index = ui->listWidget->currentRow();
    auto it = students.begin();
    it += index;
    students.erase(it);
    ui->listWidget->takeItem(index);
    this->write_data(DATA_PATH);
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    static QListWidgetItem * mem = NULL;
    if(mem == item) {
        if(ui->add_pb->text() == QString("Edit")) {
            ui->listWidget->clearSelection();
            this->clear_formdata();
        } else if(ui->add_pb->text() == QString("Add")) {
            this->on_listWidget_currentRowChanged(ui->listWidget->currentRow());
        }

    }
    else
        mem = item;
}
