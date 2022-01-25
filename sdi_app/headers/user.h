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
    string type;
public:
    void set_type(string m);
    string get_type();
    void registration();
    void sign_in();
    void order_history();
    void sign_out();
};

#endif //SDI_APP_USER_H
