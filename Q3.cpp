#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

struct Employee {
    int id;
    string name;
    float salary;
};

int main() {
    
    const int NUM_EMPLOYEES = 10;
    Employee employees[NUM_EMPLOYEES];

    cout << "--- Enter details for " << NUM_EMPLOYEES << " employees ---" << endl;


    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        cout << "\nEmployee " << (i + 1) << ":" << endl;

        cout << "Enter ID: ";
        cin >> employees[i].id;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Name: ";
        getline(cin, employees[i].name);

        cout << "Enter Salary: ";
        cin >> employees[i].salary;
    }

    cout << "\n--- Employee Data Entry Complete ---" << endl;

    int choice;
    
    do {
        cout << "\n========== Employee Menu ==========" << endl;
        cout << "1. Display all employee details" << endl;
        cout << "2. Search for an employee by ID" << endl;
        cout << "3. Exit" << endl;
        cout << "===================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                
                cout << "\n--- All Employee Details ---" << endl;
                cout << fixed << setprecision(2);
                for (int i = 0; i < NUM_EMPLOYEES; ++i) {
                    cout << "ID: " << employees[i].id
                         << ", Name: " << employees[i].name
                         << ", Salary: $" << employees[i].salary << endl;
                }
                break;

            case 2: {
            
                int searchId;
                bool found = false;
                cout << "\nEnter Employee ID to search for: ";
                cin >> searchId;

                for (int i = 0; i < NUM_EMPLOYEES; ++i) {
                    if (employees[i].id == searchId) {
                        cout << "\n--- Employee Found ---" << endl;
                        cout << "ID: " << employees[i].id
                             << ", Name: " << employees[i].name
                             << ", Salary: $" << employees[i].salary << endl;
                        found = true;
                        break; 
                    }
                }

                if (!found) {
                    cout << "\nEmployee with ID " << searchId << " not found." << endl;
                }
                break;
            }
            case 3:
                
                cout << "\nExiting program. Goodbye!" << endl;
                break;

            default:
                cout << "\nInvalid choice. Please enter 1, 2, or 3." << endl;
        }

    } while (choice != 3);

    return 0;
}
