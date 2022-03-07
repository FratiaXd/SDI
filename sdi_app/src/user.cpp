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

string User::encrypt(string value) {
    int i;
    char* arr;
    string n_obj(value);
    arr = &n_obj[0];
    for(i = 0; (i < 100 && arr[i] != '\0'); i++) {
        arr[i] = arr[i] + 2;
    }
    string str(arr);
    return str;
}

string User::decrypt(string value) {
    int i;
    char* arr;
    string n_obj(value);
    arr = &n_obj[0];
    for(i = 0; (i < 100 && arr[i] != '\0'); i++){
        arr[i] = arr[i] - 2;
    }
    string str(arr);
    return str;
}

void User::set_n(string u) {
    username = u;
}

string User::get_n() {
    return username;
}

string User::get_fulln() {
    return full_name;
}

string User::get_email() {
    return email;
}

string User::get_mobile() {
    return mobile;
}

string User::get_address() {
    return address;
}

void User::registration() {
    connection C("dbname = postgres user = postgres password = kek228 hostaddr = 127.0.0.1 port = 5432");
    if (C.is_open()) {
        cout << "Opened database successfully: " << C.dbname() << endl;
    }
    else {
        cout << "Can't open database" << endl;
    }
    string unm = encrypt(username);
    string pw = encrypt(password);
    string f_nm = encrypt(full_name);
    string ema = encrypt(email);
    string mob = encrypt(mobile);
    string add = encrypt(address);

    string sql = "INSERT INTO USERS(USERNAME, PASSWORD, FULLNAME, EMAIL, MOBILE, TYPE, ADDRESS)" \
                 "VALUES('"+ unm + "', '" + pw + "', '" + f_nm + "', '" + ema + "', '" + mob + "', '" + type + "', '" + add + "');";

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
    string u = encrypt(usnm);
    string p = encrypt(psswrd);
    string sql = "SELECT EXISTS(SELECT 1 FROM USERS WHERE username = '" + u + "' AND password = '" + p + "');";

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

    string n = encrypt(usn);
    string tpe;
    string sql = "SELECT type FROM USERS WHERE username = '" + n + "';";

    nontransaction N(C);

    result R(N.exec(sql));

    for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
        tpe =  c[0].as<string>();
    }

    if (tpe == "driver"){

        return 4;
    }
    else if (tpe == "forwarder"){
        //set username
        return 5;
    }
    else if (tpe == "cargo owner"){
        //
        return 6;
    }
    else if (tpe == "receiver"){
        //
        return 7;
    }
    else {
        //
        return 8;
    }
}
