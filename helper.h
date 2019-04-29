#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <QString>

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

#endif // HELPER_H
