//
// Created by fratia on 1/21/22.
//
#include "string"
#include <pqxx/pqxx>
using namespace std;

#ifndef SDI_APP_USER_H
#define SDI_APP_USER_H

class User {
protected:
    string username;
    string password;
    string full_name;
    string email;
    string mobile;
    string type;
    string address;
public:
    void set_type(string m);
    string get_type();
    User();
    User(string u, string p, string f_n, string em, string num, string t, string a);
    void registration();
    bool sign_in(string usnm, string psswrd);
    int open_menu(string usn);
    void order_history();
    void sign_out();
};

#endif //SDI_APP_USER_H
