//
// Created by fratia on 1/21/22.
//
#include "string"

using namespace std;

#ifndef SDI_APP_CARGO_H
#define SDI_APP_CARGO_H

class Cargo {
protected:
    string cargoID;
    double weight;
    double height;
    double width;
    double lenght;
    string type;
    string source;
    string destination;
    double shippingCost;
    string owner;
    string forwarder;
    string company;
    string driver;
    string receiver;
public:
    void assign_owner();
    void assign_forwarder();
    void assign_driver();
    void assign_company();
    void assign_receiver();
};

#endif //SDI_APP_CARGO_H
