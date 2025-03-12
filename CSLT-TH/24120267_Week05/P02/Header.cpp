#include "header.h"

void inputStudent(vector<Student>& students) {
    string line;
    int emptyLine = 0;

    while (true) {
        Student student;

        getline(cin, student.id);
        if (student.id.empty()) break;
        getline(cin, student.fullname);
        cin >> student.gpa;
        cin.ignore();
        getline(cin, student.address);
        cin >> student.bday >> student.bmonth >> student.byear;
        cin.ignore();
        students.push_back(student);
    }
}

void outputStudent(const vector<Student>& students) {
    for (size_t i = 0; i < students.size(); ++i) {
        const Student& student = students[i];
        cout << "Student " << (i + 1) << ": " << endl;
        cout << "ID: " << student.id << endl;
        cout << "Name: " << student.fullname << endl;
        cout << "GPA: " << student.gpa << endl;
        cout << "Address: " << student.address << endl;
        cout << "Birthday: " << student.bday << "/" << student.bmonth << "/" << student.byear << endl;
        cout << endl;
    }
}

void outputStudent2(const vector<Student>& students) {
    for (size_t i = 0; i < students.size(); ++i) {
        const Student& student = students[i];

        size_t spacePos = student.fullname.find(' ');
        string firstName, lastName;
        if (spacePos != string::npos) {
            firstName = student.fullname.substr(spacePos + 1);
            lastName = student.fullname.substr(0, spacePos);
        }
        else {
            firstName = student.fullname;
        }

        time_t now = time(0);
        tm* currentTime = localtime(&now);
        int currentYear = currentTime->tm_year + 1900;
        int currentMonth = currentTime->tm_mon + 1;
        int currentDay = currentTime->tm_mday;

        int age = currentYear - student.byear;
        if (currentMonth < student.bmonth || (currentMonth == student.bmonth && currentDay < student.bday)) {
            age--;
        }

        cout << "Student " << (i + 1) << ": " << endl;
        cout << "ID: " << student.id << endl;
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "GPA: " << student.gpa << endl;
        cout << "Address: " << student.address << endl;
        cout << "Birthday: " << student.bday << "/" << student.bmonth << "/" << student.byear << endl;
        cout << "Age: " << age << endl;
        cout << endl;
    }
}

void classK(const vector<Student>& students) {
    for (size_t i = 0; i < students.size(); ++i) {
        const Student& student = students[i];

        if (student.id.substr(0, 2) == "19") {
            cout << "Student " << (i + 1) << ": " << endl;
            cout << "ID: " << student.id << endl;
            cout << "Name: " << student.fullname << endl;
            cout << "GPA: " << student.gpa << endl;
            cout << "Address: " << student.address << endl;
            cout << "Birthday: " << student.bday << "/" << student.bmonth << "/" << student.byear << endl;
            cout << endl;
        }
    }
}

bool compareID(const Student& a, const Student& b) {
    return a.id < b.id;
}

bool compareGPA(const Student& a, const Student& b) {
    return a.gpa < b.gpa;
}

bool compareName(const Student& a, const Student& b) {
    return a.fullname < b.fullname;
}

void compareId(vector<Student>& students) {
    sort(students.begin(), students.end(), compareID);

    for (size_t i = 0; i < students.size(); ++i) {
        const Student& student = students[i];
        cout << "Student " << (i + 1) << ": " << endl;
        cout << "ID: " << student.id << endl;
        cout << "Name: " << student.fullname << endl;
        cout << "GPA: " << student.gpa << endl;
        cout << "Address: " << student.address << endl;
        cout << "Birthday: " << student.bday << "/" << student.bmonth << "/" << student.byear << endl;
        cout << endl;
    }
}

void compareGpa(vector<Student>& students) {
    sort(students.begin(), students.end(), compareGPA);

    for (size_t i = 0; i < students.size(); ++i) {
        const Student& student = students[i];
        cout << "Student " << (i + 1) << ": " << endl;
        cout << "ID: " << student.id << endl;
        cout << "Name: " << student.fullname << endl;
        cout << "GPA: " << student.gpa << endl;
        cout << "Address: " << student.address << endl;
        cout << "Birthday: " << student.bday << "/" << student.bmonth << "/" << student.byear << endl;
        cout << endl;
    }
}

void compareNAME(vector<Student>& students) {
    sort(students.begin(), students.end(), compareName);

    for (size_t i = 0; i < students.size(); ++i) {
        const Student& student = students[i];
        cout << "Student " << (i + 1) << ": " << endl;
        cout << "ID: " << student.id << endl;
        cout << "Name: " << student.fullname << endl;
        cout << "GPA: " << student.gpa << endl;
        cout << "Address: " << student.address << endl;
        cout << "Birthday: " << student.bday << "/" << student.bmonth << "/" << student.byear << endl;
        cout << endl;
    }
}