#include "header.h"

void inputCourse(Course& course) {
    cin >> course.cID;
    cin.ignore();
    getline(cin, course.cName);
    cin >> course.status >> course.maxStu >> course.minStu >> course.totalStu;
    cin.ignore();

    course.stu.clear();
    for (int i = 0; i < course.totalStu; ++i) {
        Student student;
        cin >> student.id;
        cin.ignore();
        getline(cin, student.name);
        cin >> student.bday >> student.bmonth >> student.byear >> student.gpa;
        course.stu.push_back(student);
    }
}

void outputCourse(const Course& course) {
    cout << "ID: " << course.cID << endl;
    cout << "Course Name: " << course.cName << endl << endl;

    for (int i = 0; i < course.totalStu; ++i) {
        const Student& student = course.stu[i];
        cout << "Student " << (i + 1) << ": " << endl;
        cout << "ID: " << student.id << endl;
        cout << "Name: " << student.name << endl;
        cout << "Birthday: " << student.bday << "/" << student.bmonth << "/" << student.byear << endl;
        cout << "GPA: " << student.gpa << endl;
        cout << endl;
    }
}

bool addStudent(Course& course, const Student& student) {
    if ((course.status == "Open" || course.status == "open") && course.stu.size() < course.maxStu) {
        course.stu.push_back(student);
        course.totalStu++;
        return true;
    }
    return false;
}

bool removeStudent(Course& course, const string& studentID) {
    for (size_t i = 0; i < course.stu.size(); ++i) {
        if (course.stu[i].id == studentID) {
            course.stu.erase(course.stu.begin() + i);
            return true;
        }
    }
    return false;
}

void findStudent1(const Course& course, int month) {
    bool haveStu = false;
    for (const auto& student : course.stu) {
        if (student.bmonth == month) {
            cout << student.name << ", " << student.id << endl;
            haveStu = true;
        }
    }
    if (!haveStu) cout << "0";
}

void findStudent2(const Course& course,int day, int month) {
    bool haveStu = false;
    for (const auto& student : course.stu) {
        if (student.bmonth == month && student.bday == day) {
            cout << student.name << ", " << student.id << endl;
            haveStu = true;
        }
    }
    if (!haveStu) cout << "0";
}

void findStudent3(const Course& course, int day, int month, int year) {
    bool haveStu = false;
    for (const auto& student : course.stu) {
        if (student.bmonth >= month && student.bday >= day && (year - student.byear) >= 18) {
            cout << student.name << ", " << student.id << endl;
            haveStu = true;
        }
    }
    if (!haveStu) cout << "0";
}

void k19Stu(const Course& course) {
    bool k19 = false;
    for (const auto& student : course.stu) {
        if (student.id.substr(0,2) == "19") {
            cout << student.name << ", " << student.id << endl;
            k19 = true;
        }
    }
    if (!k19) cout << "0";
}

void scanID(const Course& course, string ID) {
    for (const auto& student : course.stu) {
        if (student.id == ID) {
            cout << "ID: " << student.id << endl;
            cout << "Name: " << student.name << endl;
            cout << "Birthday: " << student.bday << "/" << student.bmonth << "/" << student.byear << endl;
            cout << "GPA: " << student.gpa << endl;
            cout << endl;
        }
    }
}

void scanName(const Course& course, string Name) {
    for (const auto& student : course.stu) {
        if (student.name.find(Name) != string::npos) {
            cout << "ID: " << student.id << endl;
            cout << "Name: " << student.name << endl;
            cout << "Birthday: " << student.bday << "/" << student.bmonth << "/" << student.byear << endl;
            cout << "GPA: " << student.gpa << endl;
            cout << endl;
        }
    }
}

bool compareId(const Student& a, const Student& b) {
    return a.id < b.id;
}

void sortByID(Course& course) {
    std::sort(course.stu.begin(), course.stu.end(), compareId);

    for (const auto& student : course.stu) {
        cout << "ID: " << student.id << endl;
        cout << "Name: " << student.name << endl;
        cout << "Birthday: " << student.bday << "/" << student.bmonth << "/" << student.byear << endl;
        cout << "GPA: " << student.gpa << endl;
        cout << endl;
    }
}

bool compareName(const Student& a, const Student& b) {
    return a.name < b.name;
}

void sortByName(Course& course) {
    sort(course.stu.begin(), course.stu.end(), compareName);

    for (const auto& student : course.stu) {
        cout << "ID: " << student.id << endl;
        cout << "Name: " << student.name << endl;
        cout << "Birthday: " << student.bday << "/" << student.bmonth << "/" << student.byear << endl;
        cout << "GPA: " << student.gpa << endl;
        cout << endl;
    }
}

bool compareGPA(const Student& a, const Student& b) {
    return a.gpa < b.gpa;
}

void sortByGPA(Course& course) {
    sort(course.stu.begin(), course.stu.end(), compareGPA);

    for (const auto& student : course.stu) {
        cout << "ID: " << student.id << endl;
        cout << "Name: " << student.name << endl;
        cout << "Birthday: " << student.bday << "/" << student.bmonth << "/" << student.byear << endl;
        cout << "GPA: " << student.gpa << endl;
        cout << endl;
    }
}

bool compareDOB(const Student& a, const Student& b) {
    return a.bday < b.bday;
}

void sortByDOB(Course& course) {
    sort(course.stu.begin(), course.stu.end(), compareDOB);

    for (const auto& student : course.stu) {
        cout << "ID: " << student.id << endl;
        cout << "Name: " << student.name << endl;
        cout << "Birthday: " << student.bday << "/" << student.bmonth << "/" << student.byear << endl;
        cout << "GPA: " << student.gpa << endl;
        cout << endl;
    }
}