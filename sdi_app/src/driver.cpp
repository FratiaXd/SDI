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

void Driver::set_driver(string u, string p, string f_n, string em, string num, string t, string a) {
    username = u;
    password = p;
    full_name = f_n;
    email = em;
    mobile = num;
    type = t;
    address = a;
}

void Driver::driver_details(string ni, string lid, string tp, string reg, string he, string wi, string le, string we, string cp) {
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

void Driver::registration_driver() {
    connection C("dbname = postgres user = postgres password = kek228 hostaddr = 127.0.0.1 port = 5432");
    if (C.is_open()) {
        cout << "Opened database successfully: " << C.dbname() << endl;
    }
    else {
        cout << "Can't open database" << endl;
    }
    string sql = "INSERT INTO USERS(USERNAME, PASSWORD, FULLNAME, EMAIL, MOBILE, TYPE, ADDRESS," \
                 "NINUMBER, LICENSEID, LORRY_TYPE, REGISTRATION_NUM, L_HEIGHT, L_WIDTH, L_LENGHT, L_WEIGHT, CPC)" \
                 "VALUES('"+ username + "', '" + password + "', '" + full_name + "', '" + email + "', '" + mobile + "', '" + type + "', '" + address + "', '" \
                 + NI_number + "', '" + driverlID + "', '" + lorryType + "', '" + lorryRegNum + "', '" + lorryHeight + "', '" + lorryWidth + "', '" + lorryLenght + "', '" + lorryWeight + "', '" + cpc + "');";

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
