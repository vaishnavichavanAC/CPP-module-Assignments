//============================================================================
// Name        : SensorReadingClassifier.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	double c;  /// c is temperature in celcius
	int code;
	double f;
	string status;
	string action;
    cout<<"enter the temprature: ";
    cin>>c;
    f= 	(c*9/5)+32;
    cout<<"Temperature:"<< c<<"\u00B0C"<<"/ "<<f<<"\u00B0F"<<endl;

	if(c<0){
		code= -1;
		status = "SENSOR_ERROR";
		action="Senor fault -check wiring";
//		cout<<"code:" <<code<<endl;
		cout<<"status: " <<status<<endl;
      }
	else if(c>0 && c< 29){
		code= 0;
		status = "NORMAL";
		action="No action required";
//		cout<<"code:" <<code<<endl;
		cout<<"status: " <<status<<endl;

	}
	else if(c>30 && c< 44){
		code= 1;
		status = "WARNING";
		action="Alert send to supervisor";
//			cout<<"code:" <<code<<endl;
			cout<<"status: " <<status<<endl;

		}
	else if(c>45 && c< 59){
		code= 2;
		status = "CRITICAL";
		action="Cooling system triggered";
//			cout<<"code:" <<code<<endl;
			cout<<"status: " <<status<<endl;

		}
	else {
		    code= 3;
		    status = "SHUTDOWN";
		    action="emergency Shutdown Initiated";
//			cout<<"code:" <<code<<endl;
			cout<<"status: " <<status<<endl;

		}

	switch(code){
	case -1:
		cout<<"Action: "<<action<<endl;
		break;
	case 0:
		cout<<"Action: "<<action<<endl;
		break;
	case 1:
		cout<<"Action: "<<action<<endl;
		break;
	case 2:
		cout<<"Action: "<<action<<endl;
		break;
	case 3:
		cout<<"Action: "<<action<<endl;
	}

	string reading = (c>25)?"Above Average": "Below Average";
	cout<<"Reading: "<<reading<<endl;

return 0;
}
