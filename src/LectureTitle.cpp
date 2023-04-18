//
// Created by Legion on 4/18/2023.
//
#include <string>
using std::string;

struct Specialization{
    string specialization;
    explicit Specialization(string specialization_){
        specialization = specialization_;
    }
};

struct Course{
    string course;
    explicit Course(string course_){
        course = course_;
    }
};

struct Week{
    string week;
    explicit Week(string week_){
        week = week_;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle(Specialization specialization_, Course course_, Week week_){
        this->specialization = specialization_.specialization;
        this->course = course_.course;
        this->week = week_.week;
    }
};
