#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    if(currentRow < 0)
        return;
    cout << currentRow << endl;
    auto current_stu = students[currentRow];
    ui->first_name_le->setText(current_stu.first_name);
    ui->last_name_le->setText(current_stu.last_name);
    ui->add_pb->setText("Edit");
}

void MainWindow::on_add_pb_clicked()
{
    QString first = ui->first_name_le->text();
    QString last = ui->last_name_le->text();
    if(ui->add_pb->text() == QString("Add")) {
        Data::Student new_stu = Data::Student(first, last);
        ui->first_name_le->clear();
        ui->last_name_le->clear();
        this->students.push_back(new_stu);
        ui->listWidget->addItem(new_stu.get_name());
    } else if(ui->add_pb->text() == QString("Edit")) {

    }
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
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    static QListWidgetItem * mem = NULL;
    if(mem == item) {
        ui->listWidget->clearSelection();
        ui->first_name_le->clear();
        ui->last_name_le->clear();
        ui->add_pb->setText("Add");
    }
    else
        mem = item;
}
