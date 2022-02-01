//
// Created by fratia on 1/21/22.
//
#include "headers/cargo_owner.h"

using namespace std;

CargoOwner::CargoOwner() {

}

CargoOwner::CargoOwner(string u, string p, string f_n, string em, string num, string t, string a) {
    username = u;
    password = p;
    full_name = f_n;
    email = em;
    mobile = num;
    type = t;
    address = a;
}

double CargoOwner::calculate_shipping() {

}

void CargoOwner::place_order() {

}

