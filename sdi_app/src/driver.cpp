//
// Created by fratia on 1/21/22.
//
#include "headers/driver.h"
#include <pqxx/pqxx>
#include "iostream"

using namespace pqxx;
using namespace std;

Driver::Driver() {

}

Driver::Driver(string n, string p, string nf, string e, string m, string t, string a, string ni, string lid, string tp,
               string reg, string he, string wi, string le, string we, string cp) {
    username = n;
    password = p;
    full_name = nf;
    email = e;
    mobile = m;
    type = t;
    address = a;
    NI_number = ni;
    driverlID = lid;
    lorryType = tp;
    lorryRegNum = reg;
    lorryHeight = he;
    lorryWidth = wi;
    lorryLenght = le;
    lorryWeight = we;
    cpc = cp;
}

void Driver::registration_driver(string n, string p, string nf, string e, string m, string t, string a, \
                                 string ni, string lid, string tp, string reg, string he, string wi,    \
                                 string le, string we, string cpc) {
    connection C("dbname = postgres user = postgres password = kek228 hostaddr = 127.0.0.1 port = 5432");
    if (C.is_open()) {
        cout << "Opened database successfully: " << C.dbname() << endl;
    }
    else {
        cout << "Can't open database" << endl;
    }
    string sql = "INSERT INTO USERS(USERNAME, PASSWORD, FULLNAME, EMAIL, MOBILE, TYPE, ADDRESS," \
                 "NINUMBER, LICENSEID, LORRY_TYPE, REGISTRATION_NUM, L_HEIGHT, L_WIDTH, L_LENGHT, L_WEIGHT, CPC)" \
                 "VALUES('"+ n + "', '" + p + "', '" + nf + "', '" + e + "', '" + m + "', '" + t + "', '" + a + "', '" \
                 + ni + "', '" + lid + "', '" + tp + "', '" + reg + "', '" + he + "', '" + wi + "', '" + le + "', '" + we + "', '" + cpc + "');";

    work W(C);

    W.exec(sql);
    W.commit();
    cout << "User saved" << endl;
}

bool Driver::check_cpc() {

}

void Driver::see_cargo_order() {

}

void Driver::update_order() {

}
