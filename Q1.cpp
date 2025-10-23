#include <iostream>
#include <string>
#include <algorithm> 
#include <iomanip>   
#include <limits>    

using namespace std;

struct Item {
    int id;
    string name;
    float cost;
};

bool compareItems(const Item& a, const Item& b) {
  
    return a.cost > b.cost;
}

int main() {
    
    const int NUM_ITEMS = 8;
    Item items[NUM_ITEMS];
    double totalCost = 0.0;

    cout << "--- Enter details for " << NUM_ITEMS << " items ---" << endl;

    
    for (int i = 0; i < NUM_ITEMS; ++i) {
        cout << "\nItem " << (i + 1) << ":" << endl;
        
        cout << "Enter ID: ";
        cin >> items[i].id;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        
        cout << "Enter Name: ";
        getline(cin, items[i].name);

        cout << "Enter Cost: ";
        cin >> items[i].cost;

        
        totalCost += items[i].cost;
    }

    
    sort(items, items + NUM_ITEMS, compareItems);

  
    cout << "\n--- Sorted List of Items (Descending by Cost) ---" << endl;
    cout << fixed << setprecision(2); 
    for (int i = 0; i < NUM_ITEMS; ++i) {
        cout << "ID: " << items[i].id 
             << ", Name: " << items[i].name
             << ", Cost: $" << items[i].cost << endl;
    }

    
    double averageCost = totalCost / NUM_ITEMS;
    cout << "\n--------------------------------------------------" << endl;
    cout << "Average cost of all items: $" << averageCost << endl;

    return 0;
}
