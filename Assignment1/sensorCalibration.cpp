//============================================================================
// Name        : bug.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//call by value
void resetSensorPairV1(int reading1, int reading2){
int temp = reading1;
reading1 = reading2;
reading2 = temp;
}

//call by refernce
void resetSensorPairV2(int& reading1, int& reading2){
	int temp = reading1;
	reading1 = reading2;
	reading2 = temp;
}
void resetSensorPairV3(int* reading1, int* reading2){
int temp = *reading1;
	*reading1 = *reading2;
	*reading2 = temp;
}
int main() {
int reading1=55;
int reading2=12;
cout<<"Call by value------------"<<endl;
cout<<"Before swapping - reading1: "<<reading1 << " reading2: "<< reading2 <<endl;
resetSensorPairV1(reading1,reading2);
cout<<"After swapping - reading1: "<<reading1 << " reading2: "<< reading2 <<endl;
cout<<endl;
cout<<"Call by refernce------------"<<endl;
cout<<"Before swapping - reading1: "<<reading1 << " reading2: "<< reading2 <<endl;
resetSensorPairV2(reading1,reading2);
cout<<"After swapping - reading1: "<<reading1 << " reading2: "<< reading2 <<endl;
cout<<endl;
cout<<"Call by pointer------------"<<endl;
cout<<"Before swapping - reading1: "<<reading1 << " reading2: "<< reading2 <<endl;
resetSensorPairV3(&reading1,&reading2);
cout<<"After swapping - reading1: "<<reading1 << " reading2: "<< reading2 <<endl;

return 0;
}
