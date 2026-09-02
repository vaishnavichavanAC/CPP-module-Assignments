//============================================================================
// Name        : InventoryManagementSystem.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include<set>
using namespace std;

class Product{
	int productId;
	string name;
	double price;
	int quantity;
public:
	void acceptDetails(){ // Read all fields from user

	cout<<"enter the productId: "<<endl;
	cin>>productId;

	cout<<"enter the name: "<<endl;
	cin>>name;

	cout<<"enter the price: "<<endl;
	cin>>price;

	cout<<"enter the quantity: "<<endl;
	cin>>quantity;

	cout << "-------------------------" << endl;
	}


	 void displayDetails() const {

	        cout << left << setw(8) << productId
	             << setw(15) << name
	             << setw(10) << fixed << setprecision(2) << price
	             << setw(8) << quantity
	             << setw(15) << totalValue();

	    } // Print formatted product info





	double totalValue() const{

		return price * quantity;

	} // price * quantity



	bool isLowStock(int threshold) const{

		return quantity < threshold;
	}// true if quantity < threshold

	string getName() const { return name; }

};

int main() {

    Product products[5];

    int threshold;
    cout << "Enter low stock threshold: ";
    cin >> threshold;
    cout << endl;


    for (int i = 0; i < 5; i++) {
         cout << "Product " << (i + 1) << ":" << endl;
         products[i].acceptDetails();
    }


    cout << "\n============ INVENTORY REPORT ===============\n";
    cout << left << setw(8) << "ID"
         << setw(15) << "Name"
         << setw(10) << "Price"
         << setw(8) << "Qty"
         << setw(15) << "Total Value" << endl;


    for (int i = 0; i < 5; i++) {
        products[i].displayDetails();


        if (products[i].isLowStock(threshold)) {
            cout << " ← LOW STOCK";
        }
        cout << endl;
    }


    int highestIndex = 0;
    for (int i = 1; i < 5; i++) {
        if (products[i].totalValue() > products[highestIndex].totalValue()) {
            highestIndex = i;
        }
    }
    cout << "\nHighest Value Product : " << products[highestIndex].getName()
         << " (Rs. " << fixed << setprecision(2) << products[highestIndex].totalValue() << ")" << endl;


    cout << "Low Stock (threshold: " << threshold << ") : ";
    bool foundLowStock = false;
    for (int i = 0; i < 5; i++) {
        if (products[i].isLowStock(threshold)) {
            if (foundLowStock) {
                cout << ", ";
            }
            cout << products[i].getName();
            foundLowStock = true;
        }
    }
    if (!foundLowStock) {
        cout << "None";
    }
    cout << endl;

    return 0;
}
