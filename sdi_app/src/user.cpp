//
// Created by fratia on 1/21/22.
//
#include "headers/user.h"
#include "iostream"

using namespace pqxx;
using namespace std;

User::User() {

}

User::User(string u, string p, string f_n, string em, string num, string t, string a) {
    username = u;
    password = p;
    full_name = f_n;
    email = em;
    mobile = num;
    type = t;
    address = a;
}

void User::set_type(string m) {
    type = m;
}

string User::get_type() {
    return type;
}

void User::registration(string n, string p, string nf, string e, string m, string t, string a) {
    connection C("dbname = postgres user = postgres password = kek228 hostaddr = 127.0.0.1 port = 5432");
    if (C.is_open()) {
        cout << "Opened database successfully: " << C.dbname() << endl;
    }
    else {
        cout << "Can't open database" << endl;
    }
    string sql = "INSERT INTO USERS(USERNAME, PASSWORD, FULLNAME, EMAIL, MOBILE, TYPE, ADDRESS)" \
                 "VALUES('"+ n + "', '" + p + "', '" + nf + "', '" + e + "', '" + m + "', '" + t + "', '" + a + "');";

    work W(C);

    W.exec(sql);
    W.commit();
    cout << "User saved" << endl;
}

void User::sign_in() {

}

void User::order_history() {

}

void User::sign_out() {

}