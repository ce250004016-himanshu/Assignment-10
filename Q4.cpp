#include <iostream>
#include <fstream>  
#include <string>
#include <iomanip>  

using namespace std; 
struct SalesRecord {
    string month;
    float amount;
};

int main() {
    const int NUM_MONTHS = 12;
    SalesRecord sales[NUM_MONTHS];
    float totalSales = 0;

    
    string monthNames[NUM_MONTHS] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    
    cout << "--- Enter Sales Data ---" << endl;
    for (int i = 0; i < NUM_MONTHS; ++i) {
        sales[i].month = monthNames[i];
        cout << "Enter sales for " << sales[i].month << ": $";
        cin >> sales[i].amount;
        totalSales += sales[i].amount;
    }
    cout << "\nData entry complete." << endl;

  
    ofstream outFile("sales_data.txt"); 

    if (!outFile) {
        cerr << "Error: Could not open sales_data.txt for writing." << endl;
        return 1; 
    }

    for (int i = 0; i < NUM_MONTHS; ++i) {
        
        outFile << sales[i].month << " " << sales[i].amount << endl;
    }
    outFile.close(); // Always close the file when done
    cout << "Data successfully written to sales_data.txt." << endl;

  
    SalesRecord readData[NUM_MONTHS]; 
    float readTotal = 0;
    int count = 0;

    ifstream inFile("sales_data.txt") ;

    if (!inFile) {
        cerr << "Error: Could not open sales_data.txt for reading." << endl;
        return 1; 
    }

    cout << "\n--- Reading Data From File ---" << endl;
    
    while (count < NUM_MONTHS && inFile >> readData[count].month >> readData[count].amount) {
        cout << "Read: " << readData[count].month << ", $" 
             << fixed << setprecision(2) << readData[count].amount << endl;
        
        readTotal += readData[count].amount; 
        count++;
    }
    inFile.close();

  
    if (count != NUM_MONTHS) {
        cerr << "Error: File did not contain 12 months of data." << endl;
        return 1;
    }

    
    float averageSales = readTotal / NUM_MONTHS;

    cout << "\n--- Sales Analysis ---" << endl;
    cout << "Total Yearly Sales: $" << fixed << setprecision(2) << readTotal << endl;
    cout << "Average Monthly Sales: $" << fixed << setprecision(2) << averageSales << endl;
    
    cout << "\nMonths with above-average sales:" << endl;
    bool foundAboveAverage = false;
    for (int i = 0; i < NUM_MONTHS; ++i) {
        if (readData[i].amount > averageSales) {
            cout << "- " << readData[i].month << " ($" 
                 << fixed << setprecision(2) << readData[i].amount << ")" << endl;
            foundAboveAverage = true;
        }
    }

    if (!foundAboveAverage) {
        cout << "No months had sales above the yearly average." << endl;
    }

    return 0; 
}
