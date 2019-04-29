#ifndef JSON_HANDLER_H
#define JSON_HANDLER_H

#include <iostream>
#include <iomanip>
#include "json.h"
#include <fstream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

void MainWindow::json_desrialize(string path) {
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
    ui->listWidget->clear();
    for (auto i = j["students"].begin();i != j["students"].end(); i++) {
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

void MainWindow::json_serialize(string path) {
    ui->notification_label->setText(QString("Saving..."));
    ofstream json_file(path);
    nlohmann::json j;
    j["students"] = vector<map<string, string> >();
    for(unsigned long i = 0; i < this->students.size(); i++) {
        map<string, string> stu;
        stu["first_name"] = students[i].first_name.toStdString();
        stu["last_name"] = students[i].last_name.toStdString();
        stu["gender"] = to_string(students[i].gender);
        stu["age"] = to_string(students[i].age);
        stu["stu_id"] = students[i].stu_id.toStdString();
        j["students"].push_back(stu);
    }
    json_file << setw(4) << j;
    json_file.close();
    ui->notification_label->setText(QString(""));
}

#endif // JSON_HANDLER_H
