#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "json_handler.h"
#include "helper.h"
#include <qfiledialog.h>

using namespace std;

MainWindow::MainWindow(std::string data_path, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->set_data_path(data_path);
    json_desrialize(this->data_path);
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

    // Checking if the input is valid
    bool abort = false;
    if(!is_character(first)) {
        abort = true;
        ui->first_name_warning->setStyleSheet("QLabel {color : red; }");
        ui->first_name_warning->setText("Should only contain char");
    } else {
        ui->first_name_warning->setText("");
    }
    if(!is_character(last)) {
        abort = true;
        ui->last_name_warning->setStyleSheet("QLabel {color : red; }");
        ui->last_name_warning->setText("Should only contain char");
    } else {
        ui->last_name_warning->setText("");
    }
    if(!is_integer(ui->age_le->text())) {
        abort = true;
        ui->age_warning->setStyleSheet("QLabel {color : red; }");
        ui->age_warning->setText("Should only contain int");
    } else {
        ui->age_warning->setText("");
    }
    if(!is_char_or_int(ui->stu_id_le->text())) {
        abort = true;
        ui->stu_id_warning->setStyleSheet("QLabel {color : red; }");
        ui->stu_id_warning->setText("Should only contain int or char");
    } else {
        ui->stu_id_warning->setText("");
    }
    if(abort)
        return;

    // Add a student or modify one
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
    if(this->save_on_modify)
        this->json_serialize(this->data_path);
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
    if(this->save_on_modify)
        this->json_serialize(this->data_path);
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

void MainWindow::on_actionSave_triggered()
{
    this->json_serialize(this->data_path);
}

void MainWindow::on_actionSave_on_edit_triggered(bool checked)
{
    this->save_on_modify = checked;
}

void MainWindow::closeEvent(QCloseEvent *event) {
    this->json_serialize(this->data_path);
}

void MainWindow::on_actionOpen_triggered()
{
    this->set_data_path(QFileDialog::getOpenFileName().toStdString());
    this->json_desrialize(this->data_path);
}

void MainWindow::on_actionSave_as_triggered()
{
    QString data_path = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                  "untitled.json");;
    this->set_data_path(data_path.toStdString());

    this->json_serialize(this->data_path);
}
