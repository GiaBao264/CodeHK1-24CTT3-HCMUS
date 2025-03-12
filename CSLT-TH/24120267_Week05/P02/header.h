#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <sstream>

using namespace std;

struct Student {
	string id;
	string fullname;
	float gpa;
	string address;
	int bday, bmonth, byear;
	int total;
};

void inputStudent(vector<Student>& students);
void outputStudent(const vector<Student>& students);
void outputStudent2(const vector<Student>& students);
void classK(const vector<Student>& students);
void compareId(vector<Student>& students);
void compareGpa(vector<Student>& students);
void compareNAME(vector<Student>& students);