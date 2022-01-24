//
// Created by fratia on 1/21/22.
//
#include "string"

using namespace std;

#ifndef SDI_APP_USER_H
#define SDI_APP_USER_H

class User {
protected:
    string username;
    string password;
    string email;
    string mobile;
public:
    User(string usnm, string psswrd, string em, string phone);
    void registration();
    void sign_in();
    void order_history();
    void sign_out();
};

#endif //SDI_APP_USER_H
