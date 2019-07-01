#include "startup.h"
#include "ui_startup.h"
#include "json_handler.h"
#include "mainwindow.h"
#include <QFileDialog>
#include <QDialog>
#include <QString>
#include <iostream>
#include <sys/stat.h>

using namespace std;

Startup::Startup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Startup)
{
    ui->setupUi(this);
}

Startup::~Startup()
{
    delete ui;
}


void Startup::on_choose_file_pb_clicked()
{
    auto data_path = QFileDialog::getOpenFileName().toStdString();
    ui->data_path_le->setText(QString::fromStdString(data_path));
}

void Startup::on_ok_pb_clicked()
{
    string data_path = ui->data_path_le->text().toStdString();
    struct stat buf;
    // check if the file exists using system call
    if(stat(data_path.c_str(), &buf) == 0) {
        // then validate the json file
        if(json_validate(data_path)) {
            MainWindow* w = new MainWindow(data_path);
            w->show();
            this->close();
        } else {
            ui->warning_label->setStyleSheet("QLabel {color : red; }");
            ui->warning_label->setText("The file is incorrect or broken. ");
        }
    } else {
        ui->warning_label->setStyleSheet("QLabel {color : red; }");
        ui->warning_label->setText("Please provide correct file path or create new file. ");
    }
}

void Startup::on_cancel_pb_clicked()
{
    this->close();
}

void Startup::on_new_file_pb_clicked()
{
    QString data_path = QFileDialog::getSaveFileName(this, tr("Create File"),
                                                  "untitled.json");;
    MainWindow* w = new MainWindow(data_path.toStdString());
    w->show();
    this->close();
}
