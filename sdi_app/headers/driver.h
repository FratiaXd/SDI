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
    double lorryHeight;
    double lorryWidth;
    double lorryLenght;
    double lorryWeight;
    string cpc;
public:
    bool check_cpc();

};

#endif //SDI_APP_DRIVER_H
