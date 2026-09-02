                  //============================================================================
// Name        : 1B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

using Header     = pair<string, string>;
using HeaderList = vector<Header>;
using Port       = unsigned int;
using IPAddress  = string;

typedef unsigned long long RequestId;


void  printHeaders(const HeaderList& headers){

cout<<"headers "<<endl;


for (const auto& head : headers) {
        // head.first is the key (like Content-Type), head.second is the value
        cout << head.first << " \t: " << head.second << endl;
    }
}


	int main() {
	    // 1. Declare and initialize tracking variables using your aliases
	    RequestId reqId = 1748293847;
	    Port serverPort = 8080;

	    // Print the tracking info first to match sample output
	    cout << "Request ID   : " << reqId << endl;
	    cout << "Server Port  : " << serverPort << endl;

	    // 2. Create a HeaderList with 3 key-value header pairs
	    HeaderList myHeaders = {
	        {"Content-Type", "application/json"},
	        {"Authorization", "Bearer eyJhbGci..."},
	        {"Accept-Language", "en-US"}
	    };
	    printHeaders(myHeaders);
	return 0;
}
