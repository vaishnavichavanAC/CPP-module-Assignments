//============================================================================
// Name        : HardwareRegisterAccess.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int statusReg  = 0b10110001;
	int controlReg = 0b00000000;
	int dataReg    = 0b11001010;

	const int* regptr1 = &statusReg;
	cout<<"regptr1: "<<*regptr1<<endl;

	/*

	*regptr1=10;
	*regptr1 = &statusReg; // The pointer can be changed, but the value cannot be modified through it.
	 cout<<*regptr1<<endl;  //Cannot modify the value through a pointer-to-const.

     */


	 int* const regptr2 = &controlReg;
		cout<<"regptr2 Before value "<<*regptr2<<endl;
		*regptr2=50;
		*regptr2 = controlReg;
		cout<<"regptr after value "<<*regptr2 <<endl;




		const int* const regptr3 = &dataReg;
		cout<<"regptr3: "<<*regptr3<<endl;

		/*
	     *regptr3=100;
		 *regptr3 = &dataReg; //Cannot change the address because the pointer itself is const.
		 cout<<*regptr3<<endl; // Error: Cannot modify the value because the pointer points to const data.
		 */



	return 0;
}
