//============================================================================
// Name        : HospitalPatientRegistry.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Patient Module matched to precise log outputs
//============================================================================

#include <iostream>
#include <string>

using namespace std;

class Patient {
private:
    int patientId;
    string name;
    int age;
    string ward;
    const string bloodGroup;

public:
    // Default Constructor
    Patient() : patientId(0), name("Unknown"), age(0), ward("General"), bloodGroup("O+") {
        cout << "[Constructor] Default patient registered." << endl;
    }

    // Constructor 2 — Emergency admission
    Patient(int id, const string& name)
        : patientId(id), name(name), age(0), ward("General"), bloodGroup("O+") {
        cout << "[Constructor] Emergency: " << name << endl;
    }

    // Constructor 3 — Full admission details
    Patient(int id, const string& name, int age, const string& ward, const string& bg)
        : patientId(id), name(name), age(age), ward(ward), bloodGroup(bg) {
        cout << "[Constructor] Full admission: " << name << endl;
    }

    // Destructor
    ~Patient() {
        cout << "[Destructor] Patient " << name << " discharged." << endl;
    }

    // Displays record fields in a vertical, custom format block
    void displayRecord() const {
        cout << "Patient Record:" << endl;
        cout << " ID : " << patientId << endl;
        cout << " Name : " << name << endl;
        cout << " Age : " << age << endl;
        cout << " Ward : " << ward << endl;
        cout << " Blood Grp : " << bloodGroup << endl;
    }

    // Updates ward and prints a simple notification string
    void transferWard(const string& newWard) {
        cout << "Ward Transfer: " << name << " → " << newWard << endl;
        ward = newWard;
    }
};

int main() {

    Patient p1(1001, "Meera Joshi", 34, "Cardiology", "B+");
    Patient p2(1002, "Raj Patel");
    Patient p3;


    Patient* bulkRegistry = new Patient[4];


    p1.displayRecord();


    p2.transferWard("ICU");


    delete[] bulkRegistry;


    return 0;
}
