//
// Created by fratia on 1/21/22.
//
#include "string"
#include "user.h"

using namespace std;

#ifndef SDI_APP_FORWARDER_H
#define SDI_APP_FORWARDER_H

class Forwarder : public User {
public:
    Forwarder();
    Forwarder(string u, string p, string f_n, string em, string num, string t, string a);
    void make_offer();
    void move_cargo();
};

#endif //SDI_APP_FORWARDER_H
