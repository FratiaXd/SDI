//
// Created by fratia on 1/21/22.
//
#include "string"
#include "user.h"

using namespace std;

#ifndef SDI_APP_CARGO_OWNER_H
#define SDI_APP_CARGO_OWNER_H

class CargoOwner : public User {
protected:
    string address;
public:
   double calculate_shipping();
   void place_order();
};

#endif //SDI_APP_CARGO_OWNER_H
