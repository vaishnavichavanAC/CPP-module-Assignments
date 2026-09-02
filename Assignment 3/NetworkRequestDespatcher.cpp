/*
 * NetworkRequestDispatcher.cpp
 *
 *  Created on: 02-Sept-2026
 *      Author: Vaishnavi
 */




#include <iostream>
#include <string>

using namespace std;


enum class HttpStatus {
    OK           = 200,
    Created      = 201,
    BadRequest   = 400,
    Unauthorized = 401,
    NotFound     = 404,
    ServerError  = 500
};


void handleResponse(HttpStatus status, const string& endpoint) {

//     cout << "[" << "] \t→ ";;

int statuscode=static_cast<int>(status);
//cout<<"Enter a statuscode"<<endl;
//cin>>statuscode;
    switch (statuscode) {
        case 200:
            cout <<endpoint<< " 200 OK             : Request successful\n";
            break;
        case 201:
            cout <<endpoint<< " Created        : Resource created successfully\n";
            break;
        case 400:
            cout <<endpoint<< " BadRequest     : Bad request formatting\n";
            break;
        case 401:
            cout <<endpoint<< " Unauthorized   : Authentication required\n";
            break;
        case 404:
            cout << endpoint<<" NotFound       : Endpoint does not exist\n";
            break;
        case 500:
            cout << endpoint<<" ServerError    : Internal server error — retry later\n";
            break;
        default:
            cout << endpoint<<" Unknown Status : Unhandled HTTP response code\n";
            break;
    }
}

int main() {

    handleResponse(HttpStatus::OK, "GET /api/users");
    handleResponse(HttpStatus::Unauthorized, "POST /api/login");
    handleResponse(HttpStatus::NotFound, "GET /api/products/99");
    handleResponse(HttpStatus::ServerError, "POST /api/order");

    return 0;
}
