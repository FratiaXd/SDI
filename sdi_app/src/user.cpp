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

void User::registration() {
    connection C("dbname = postgres user = postgres password = kek228 hostaddr = 127.0.0.1 port = 5432");
    if (C.is_open()) {
        cout << "Opened database successfully: " << C.dbname() << endl;
    }
    else {
        cout << "Can't open database" << endl;
    }
    string sql = "INSERT INTO USERS(USERNAME, PASSWORD, FULLNAME, EMAIL, MOBILE, TYPE, ADDRESS)" \
                 "VALUES('"+ username + "', '" + password + "', '" + full_name + "', '" + email + "', '" + mobile + "', '" + type + "', '" + address + "');";

    work W(C);

    W.exec(sql);
    W.commit();
    cout << "User saved" << endl;
}

bool User::sign_in(string usnm, string psswrd) {
    connection C("dbname = postgres user = postgres password = kek228 hostaddr = 127.0.0.1 port = 5432");
    if (C.is_open()) {
        cout << "Opened database successfully: " << C.dbname() << endl;
    }
    else {
        cout << "Can't open database" << endl;
    }

    bool answ;
    string sql = "SELECT EXISTS(SELECT 1 FROM USERS WHERE username = '" + usnm + "' AND password = '" + psswrd + "');";

    nontransaction N(C);

    result R(N.exec(sql));

    for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
        answ =  c[0].as<bool>();
    }
    return answ;
}

int User::open_menu(string usn) {
    connection C("dbname = postgres user = postgres password = kek228 hostaddr = 127.0.0.1 port = 5432");
    if (C.is_open()) {
        cout << "Opened database successfully: " << C.dbname() << endl;
    }
    else {
        cout << "Can't open database" << endl;
    }

    string type;
    string sql = "SELECT type FROM USERS WHERE username = '" + usn + "';";

    nontransaction N(C);

    result R(N.exec(sql));

    for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
        type =  c[0].as<string>();
    }

    if (type == "driver"){
        return 4;
    }
    else if (type == "forwarder"){
        return 5;
    }
    else if (type == "owner"){
        return 6;
    }
    else if (type == "receiver"){
        return 7;
    }
    else {
        return 8;
    }
}

void User::order_history() {

}

void User::sign_out() {

}