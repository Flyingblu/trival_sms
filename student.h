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
    int gender;         // 0:not set, 1:Male, 2:Female, 3:Other
    int age;
    QString stu_id;

    Student() {}
    Student(QString first, QString second, int g, int a, QString s): first_name(first), last_name(second), gender(g), age(a), stu_id(s) { };
    ~Student() {}
    QString get_name() {
        return this->first_name + " " + this->last_name;
    }
};

#endif // STUDENT_H
