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

string Cargo::encrypt(string value) {
    int i;
    char* arr;
    string n_obj(value);
    arr = &n_obj[0];
    for(i = 0; (i < 100 && arr[i] != '\0'); i++) {
        arr[i] = arr[i] + 4;
    }
    string str(arr);
    return str;
}

string Cargo::decrypt(string value) {
    int i;
    char* arr;
    string n_obj(value);
    arr = &n_obj[0];
    for(i = 0; (i < 100 && arr[i] != '\0'); i++){
        arr[i] = arr[i] - 4;
    }
    string str(arr);
    return str;
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

void Cargo::savetoDB() {
    connection C("dbname = postgres user = postgres password = kek228 hostaddr = 127.0.0.1 port = 5432");
    if (C.is_open()) {
        cout << "Opened database successfully: " << C.dbname() << endl;
    } else {
        cout << "Can't open database" << endl;
    }
    string a = encrypt(cargoID);
    string b = encrypt(status);
    string c = encrypt(weight);
    string d = encrypt(height);
    string e = encrypt(width);
    string f = encrypt(length);
    string g = encrypt(type);
    string h = encrypt(source);
    string i = encrypt(destination);
    string v = encrypt(shippingCost);
    string k = encrypt(owner);

    string sql = "INSERT INTO CARGO(CARGO_ID, STATUS, WEIGHT, HEIGHT, WIDTH, LENGTH, TYPE, SOURCE, DESTINATION, SHIPPING_COST, OWNER) VALUES('" + a + "', '" + b + "', '" + c + "', '" + d + "', '" + e + "', '" + f + "', '" + g + "', '" + h + "', '" + i + "', '" + v + "', '" + k + "');";

    work W(C);

    W.exec(sql);
    W.commit();
    cout << "Cargo saved" << endl;
}

void Cargo::request_history(string user, string actor) {
    connection C("dbname = postgres user = postgres password = kek228 hostaddr = 127.0.0.1 port = 5432");
    if (C.is_open()) {
        cout << "Opened database successfully: " << C.dbname() << endl;
    }
    else {
        cout << "Can't open database" << endl;
    }

    string un_en = encrypt(user);

    string sql = "SELECT CARGO_ID, STATUS, WEIGHT, HEIGHT, WIDTH, LENGTH, TYPE, SOURCE, DESTINATION, SHIPPING_COST FROM CARGO WHERE " + actor + " = '" + un_en + "';";

    nontransaction N(C);
    vector<Cargo> v1;

    result R(N.exec(sql));

    for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
        Cargo a1;
        cargoID = c[0].as<string>();
        status = c[1].as<string>();
        weight = c[2].as<string>();
        height = c[3].as<string>();
        width = c[4].as<string>();
        length = c[5].as<string>();
        type = c[6].as<string>();
        source = c[7].as<string>();
        destination = c[8].as<string>();
        shippingCost = c[9].as<string>();
        v1.push_back(a1);
    }
    //decrypt
    //sort
    //create qtree
    //delete
}