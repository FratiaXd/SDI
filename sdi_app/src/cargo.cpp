//
// Created by fratia on 1/21/22.
//
#include "headers/cargo.h"

using namespace std;
using namespace pqxx;

Cargo::Cargo() {

}

bool Cargo::cargo_exists() {
    if (weight.empty()){
        return false;
    }
    else {
        return true;
    }
}

void Cargo::set_primary_values(string w, string h, string wi, string leng, string t, string s, string d, string cost) {
    weight = w;
    height = h;
    width = wi;
    length = leng;
    type = t;
    source = s;
    destination = d;
    shippingCost = cost;
}

string Cargo::generate_id() {
    connection C("dbname = postgres user = postgres password = kek228 hostaddr = 127.0.0.1 port = 5432");
    if (C.is_open()) {
        cout << "Opened database successfully: " << C.dbname() << endl;
    }
    else {
        cout << "Can't open database" << endl;
    }

    int answ;
    string sql = "SELECT COUNT(cargo_id) FROM cargo;";

    nontransaction N(C);

    result R(N.exec(sql));

    for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
        answ =  c[0].as<int>();
    }

    int id_int = 100 + answ;

    string id = to_string(id_int);

    cargoID = id;

    return id;
}

void Cargo::update_status(string currentStatus) {
    status = currentStatus;
}

void Cargo::assign_company(string com) {
    company = com;
}

void Cargo::assign_driver(string dri) {
    drver = dri;
}

void Cargo::assign_forwarder(string forw) {
    forwarder = forw;
}

void Cargo::assign_owner(string own) {
    owner = own;
}

void Cargo::assign_receiver(string rec) {
    receiver = rec;
}