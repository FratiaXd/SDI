//
// Created by fratia on 1/21/22.
//
#include "string"
#include <pqxx/pqxx>
#include "iostream"

using namespace std;

#ifndef SDI_APP_CARGO_H
#define SDI_APP_CARGO_H

class Cargo {
protected:
    string cargoID;
    string status;
    string weight;
    string height;
    string width;
    string length;
    string type;
    string source;
    string destination;
    string shippingCost;
    string owner;
    string forwarder;
    string company;
    string drver;
    string receiver;
public:
    Cargo();
    //Cargo();
    bool cargo_exists();
    void set_primary_values(string w, string h, string wi, string leng, string t, string s, string d, string cost);
    string generate_id();
    void update_status(string currentStatus);
    void assign_owner(string own);
    void assign_forwarder(string forw);
    void assign_driver(string dri);
    void assign_company(string com);
    void assign_receiver(string rec);
};

#endif //SDI_APP_CARGO_H
