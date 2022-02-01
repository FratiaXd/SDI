//
// Created by fratia on 1/21/22.
//
#include "string"
#include "user.h"

using namespace std;

#ifndef SDI_APP_DRIVER_H
#define SDI_APP_DRIVER_H

class Driver : public User {
protected:
    string NI_number;
    string driverlID;
    string lorryType;
    string lorryRegNum;
    string lorryHeight;
    string lorryWidth;
    string lorryLenght;
    string lorryWeight;
    string cpc;
public:
    Driver();
    Driver(string n, string p, string nf, string e, string m, string t, string a,
           string ni, string lid, string tp, string reg, string he, string wi,
           string le, string we, string cpc);
    void registration_driver(string n, string p, string nf, string e, string m, string t, string a, \
                             string ni, string lid, string tp, string reg, string he, string wi,    \
                             string le, string we, string cpc);
    bool check_cpc();
    void see_cargo_order();
    void update_order();
};

#endif //SDI_APP_DRIVER_H
