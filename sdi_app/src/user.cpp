//
// Created by fratia on 1/21/22.
//
#include "headers/user.h"

using namespace std;

User::User() {

}

User::User(string u, string p, string f_n, string em, string num, string t) {
    username = u;
    password = p;
    full_name = f_n;
    email = em;
    mobile = num;
    type = t;
}

void User::set_type(string m) {
    type = m;
}

string User::get_type() {
    return type;
}

void User::registration() {

}

void User::sign_in() {

}

void User::order_history() {

}

void User::sign_out() {

}