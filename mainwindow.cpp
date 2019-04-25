#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    auto current_stu = students[currentRow];
    ui->first_name_te->setPlainText(current_stu.first_name);
    ui->last_name_te->setPlainText(current_stu.last_name);
}

void MainWindow::on_add_pb_clicked()
{
    QString first = ui->first_name_te->toPlainText();
    QString last = ui->last_name_te->toPlainText();
    Data::Student new_stu = Data::Student(first, last);
    ui->first_name_te->clear();
    ui->last_name_te->clear();
    this->students.push_back(new_stu);
    ui->listWidget->addItem(new_stu.get_name());

}

void MainWindow::on_del_pb_clicked()
{
    if(!this->students.size())
        return;
    int index = ui->listWidget->currentRow();
    auto it = students.begin();
    it += index;
    students.erase(it);
    delete ui->listWidget->currentItem();
}
