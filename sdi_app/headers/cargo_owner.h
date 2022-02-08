//
// Created by fratia on 1/21/22.
//
#include "string"
#include "user.h"

using namespace std;

#ifndef SDI_APP_CARGO_OWNER_H
#define SDI_APP_CARGO_OWNER_H

class CargoOwner : public User {
public:
    CargoOwner();
    CargoOwner(string u, string p, string f_n, string em, string num, string t, string a);
   float calculate_shipping(float w, float h, float l, float we, string src, string addr);
   void place_order();
};

#endif //SDI_APP_CARGO_OWNER_H
