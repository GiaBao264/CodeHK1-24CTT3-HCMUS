#include <iostream>
#include <fstream>

using namespace std;

int* gradeExam(char* correctAns, char* studentAns, int totalQues, int& wrongAns, double& correctPer) {
    int* wrongQues = new int[totalQues];
    wrongAns = 0;
    int correctCount = 0;

    for (int i = 0; i < totalQues; ++i) {
        if (correctAns[i] != studentAns[i]) {
            wrongQues[wrongAns++] = i + 1;
        }
        else {
            correctCount++;
        }
    }
    correctPer = (static_cast<double>(correctCount) / totalQues) * 100;

    return wrongQues;
}

int main() {
    ifstream correctFile("CorrectAnswers.txt");
    ifstream studentFile("StudentAnswers.txt");

    if (!correctFile || !studentFile) {
        cerr << "Khong the mo file!" << endl;
        return 1;
    }
    
    int totalQues;
    correctFile >> totalQues;
    studentFile >> totalQues;

    char* correctAns = new char[totalQues];
    char* studentAns = new char[totalQues];

    for (int i = 0; i < totalQues; ++i) {
        char temp;
        correctFile >> temp;
        correctAns[i] = temp;
    }

    for (int i = 0; i < totalQues; ++i) {
        char temp;
        studentFile >> temp;
        studentAns[i] = temp;
    }

    int wrongCount;
    double correctPer;
    int* wrongQuestions = gradeExam(correctAns, studentAns, totalQues, wrongCount, correctPer);

    cout << "Cau tra loi sai:" << endl;
    for (int i = 0; i < wrongCount; ++i) {
        int questionIndex = wrongQuestions[i] - 1;
        cout << "Cau " << wrongQuestions[i] << ": Dap an = " << char(correctAns[questionIndex])
            << ", Hoc sinh = " << char(studentAns[questionIndex]) << endl;
    }

    cout << "\nTong cau tra loi sai: " << wrongCount << endl;
    cout << "Phan tram tra loi sai: " << correctPer << "%" << endl;

    if (correctPer >= 70) { 
        cout << "Qua mon." << endl;
    }
    else {
        cout << "Khong qua mon." << endl;
    }

    delete[] correctAns;
    delete[] studentAns;
    delete[] wrongQuestions;

    correctFile.close();
    studentFile.close();

    return 0;
}
