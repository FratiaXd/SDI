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
    Cargo(string d, string f, string e, string r, string h,string yt, string fr, string ds, string dd, string sdv);
    bool cargo_exists();
    string encrypt(string value);
    string decrypt(string value);
    void set_primary_values(string w, string h, string wi, string leng, string t, string s, string d, string cost);
    string generate_id();
    void update_status(string currentStatus);
    void assign_owner(string own);
    void assign_forwarder(string forw);
    void assign_driver(string dri);
    void assign_company(string com);
    void assign_receiver(string rec);
    void savetoDB();
    list<Cargo> request_history(string user, string actor);
    string get_id();
    string get_status();
    string get_weight();
    string get_height();
    string get_width();
    string get_length();
    string get_type();
    string get_source();
    string get_destination();
    string get_shippingCost();
};

#endif //SDI_APP_CARGO_H
