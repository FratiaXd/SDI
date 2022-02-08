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

float CargoOwner::calculate_shipping(float w, float h, float l, float we, string src, string addr) {
    //calc
    float a = 100.6;
    return a;
}

void CargoOwner::place_order() {

}

