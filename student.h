#ifndef STUDENT_H
#define STUDENT_H
#include <QApplication>

using namespace std;

namespace Data {
class Student;
}

class Data::Student {
public:
    string first_name;
    string last_name;
//    Student(string first, string second): first_name(first), last_name(second) { };
    ~Student();
    string get_name() {
        return this->first_name + " " + this->last_name;
    }
};

#endif // STUDENT_H
