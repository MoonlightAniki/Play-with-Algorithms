//
// Created by guoliang on 2018/9/29.
//

#ifndef INC_02_SORTING_BASIC_STUDENT_H
#define INC_02_SORTING_BASIC_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int score;

    // override < operator
    bool operator<(const Student &otherStudent) {
        return this->score != otherStudent.score ?
               this->score < otherStudent.score :
               this->name < otherStudent.name;
    }

    friend ostream &operator<<(ostream &os, const Student &student) {
        os << "Student: " << student.name << " " << student.score << endl;
        return os;
    }

};

#endif //INC_02_SORTING_BASIC_STUDENT_H
