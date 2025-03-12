#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

struct Student {
    string id;
    string name;
    int bday, bmonth, byear;
    float gpa;
};

struct Course {
    string cID;
    string cName;
    vector<Student> stu;
    string status;
    int maxStu;
    int minStu;
    int totalStu;
};

void inputCourse(Course& course);
void outputCourse(const Course& course);
bool addStudent(Course& course, const Student& student);
bool removeStudent(Course& course, const string& studentID);
void findStudent1(const Course& course, int month);
void findStudent2(const Course& course, int day, int month);
void findStudent3(const Course& course, int day, int month, int year);
void k19Stu(const Course& course);
void scanID(const Course& course, string ID);
void scanName(const Course& course, string Name);
void sortByID(Course& course);
void sortByName(Course& course);
void sortByGPA(Course& course);
void sortByDOB(Course& course);