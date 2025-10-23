#include <iostream>
#include <string>
#include <limits>   
#include <iomanip>   

using namespace std;


struct Marks {
    float math;
    float science;
    float english;
};

struct Student {
    int rollNo;
    string name;
    Marks marks; 
};

int main() {
    
    const int NUM_STUDENTS = 5;
    Student students[NUM_STUDENTS];
    float averages[NUM_STUDENTS];

    cout << "--- Enter details for " << NUM_STUDENTS << " students ---" << endl;


    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "\nStudent " << (i + 1) << ":" << endl;

        cout << "Enter Roll No: ";
        cin >> students[i].rollNo;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        cout << "Enter Name: ";
        getline(cin, students[i].name);

        cout << "Enter Math marks: ";
        cin >> students[i].marks.math;

        cout << "Enter Science marks: ";
        cin >> students[i].marks.science;

        cout << "Enter English marks: ";
        cin >> students[i].marks.english;

    
        averages[i] = (students[i].marks.math + 
                       students[i].marks.science + 
                       students[i].marks.english) / 3.0;
    }

    
    int maxIndex = 0;
    int minIndex = 0;

    for (int i = 1; i < NUM_STUDENTS; ++i) {
        if (averages[i] > averages[maxIndex]) {
            maxIndex = i; 
        }
        if (averages[i] < averages[minIndex]) {
            minIndex = i; 
        }
    }
    cout << "\n--- Results ---" << endl;
    cout << fixed << setprecision(2); 

    cout << "\nStudent with HIGHEST average marks:" << endl;
    cout << "Name: " << students[maxIndex].name
         << ", Roll No: " << students[maxIndex].rollNo
         << ", Average: " << averages[maxIndex] << endl;

    cout << "\nStudent with LOWEST average marks:" << endl;
    cout << "Name: " << students[minIndex].name
         << ", Roll No: " << students[minIndex].rollNo
         << ", Average: " << averages[minIndex] << endl;

    return 0;
}
