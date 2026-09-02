#include <iostream>
#include <iomanip>

using namespace std;




double reorderCost(int qty, double unitPrice) {
    return qty * unitPrice;
}


double reorderCost(double qty, double unitPrice) {
    return qty * unitPrice;
}


double reorderCost(int qty, double unitPrice, double taxRate) {
    double baseCost = qty * unitPrice;
    return baseCost + (baseCost * (taxRate / 100.0));
}




double applyDiscount(double price, double discountPercent = 10.0) {
    return price - (price * (discountPercent / 100.0));
}

int main() {

    cout << fixed << setprecision(2);

    cout << "=== Testing Overloaded reorderCost() ===" << endl;


    double costInt = reorderCost(50, 15.50);
    cout << "Integer Qty Cost (50 units @ 15.50)       : Rs. " << costInt << endl;


    double costFloat = reorderCost(12.5, 250.00);
    cout << "Fractional Qty Cost (12.50 kg @ 250.00)   : Rs. " << costFloat << endl;


    double costTax = reorderCost(100, 100.00, 18.0);
    cout << "Qty Cost with Tax (100 units @ 100 + 18%) : Rs. " << costTax << endl;

    cout << "\n=== Testing Default Argument applyDiscount() ===" << endl;


    double discountDefault = applyDiscount(1000.00);
    cout << "Price after Default Discount (10% on 1000): Rs. " << discountDefault << endl;


    double discountCustom = applyDiscount(1000.00, 25.0);
    cout << "Price after Custom Discount (25% on 1000) : Rs. " << discountCustom << endl;

    return 0;
}

