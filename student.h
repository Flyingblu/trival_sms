#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

using namespace std;

namespace Data {
class Student;
}

class Data::Student {
public:
    QString first_name;
    QString last_name;
    int age;
    QString stu_id;

    Student() {}
    Student(QString first, QString second): first_name(first), last_name(second) { };
    ~Student() {}
    QString get_name() {
        return this->first_name + " " + this->last_name;
    }
};

#endif // STUDENT_H
