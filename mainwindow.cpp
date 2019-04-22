#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "student.h"

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

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
}
