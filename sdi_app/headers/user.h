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
    void sign_in();
    void sign_out();
};

#endif //SDI_APP_USER_H
