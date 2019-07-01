#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <QString>
#include "mainwindow.h"

using namespace std;

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

void MainWindow::set_data_path(string file_path) {
    // first validate the json file, then
    // update data_path, file_name and window title each time being called
    this->data_path = file_path;
    auto i = file_path.end() - 1;
    for(; i != file_path.begin() - 1; i--) {
        if(*i == '/')
            break;
    }
    this->file_name = string(i+1, file_path.end());
    this->setWindowTitle(QString::fromStdString(this->file_name + " - Student Management System"));
}

#endif // HELPER_H
