#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

struct Student {
    string name;
    float midterm;
    float final_exam;
    float average;
    string remark;
};

int main() {

    Student studentInfos[5];
    
    cout << "======= STUDENT GRADE REPORT ======" << endl;
    cout << "Enter five student's information..." << endl;

    for(int i = 0; i < 5; i++) {

        cout << "\nName of Student " << i + 1 << ": ";
        getline(cin, studentInfos[i].name);

        cout << "Midterm Score: ";
        cin >> studentInfos[i].midterm;

        cout << "Final Exam Score: ";
        cin >> studentInfos[i].final_exam;

        cin.ignore();

        float computedAverage = ( studentInfos[i].midterm + studentInfos[i].final_exam ) / 2;
        studentInfos[i].average = computedAverage;

        if(studentInfos[i].average >= 75) {
            studentInfos[i].remark = "Passed";
        }

        else {
            studentInfos[i].remark = "Failed";
        }
    }
    
    clearScreen();

    cout << "======= STUDENT GRADE REPORT ======" << endl;
    cout << left << setw(21) << "\nName"
     << setw(10) << "Midterm"
     << setw(9) << "Final"
     << setw(12) << "Average"
     << setw(10) << "Remark" << endl;

    cout << "----                -------   -----    -------     ------" << endl;  

    for(int i = 0; i < 5; i++) {
    cout << left << setw(22) << studentInfos[i].name
         << setw(9) << studentInfos[i].midterm
         << setw(10) << studentInfos[i].final_exam
         << setw(10) << studentInfos[i].average
         << setw(10) << studentInfos[i].remark << endl;
    }
        
    return 0;
}
