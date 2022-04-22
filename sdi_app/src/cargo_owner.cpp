//
// Created by fratia on 1/21/22.
//
#include "headers/cargo_owner.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

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

double CargoOwner::calculate_shipping(float width, float height, float length, float weight, string src, string addr) {
    // Width, Height and Length measured in meters
    // Weight measured in kilograms
    // Distance measured in kilometers
    //
    double longSource = 0;
    double latSource = 0;
    double longDest = 0;
    double latDest = 0;
    if (src == "Nottingham") {
        longSource = 52.940;
        latSource =  1.1550;
    } else if (src == "Leeds") {
        longSource = 53.8008;
        latSource =  1.5491;
    } else if (src == "Liverpool") {
        longSource = 53.4084;
        latSource =  2.9916;
    } else if (src == "London") {
        longSource = 51.5072;
        latSource =  0.1276;
    } else if (src == "Manchester") {
        longSource = 53.4808;
        latSource =  2.2426;
    } else if (src == "Birmingham") {
        longSource = 52.4862;
        latSource =  1.8904;
    } else if (src == "Edinburgh") {
        longSource = 55.9533;
        latSource =  3.1883;
    }

    if (addr == "Nottingham") {
        longDest = 52.940;
        latDest =  1.1550;
    } else if (addr == "Leeds") {
        longDest = 53.8008;
        latDest =  1.5491;
    } else if (addr == "Liverpool") {
        longDest = 53.4084;
        latDest =  2.9916;
    } else if (addr == "London") {
        longDest = 51.5072;
        latDest =  0.1276;
    } else if (addr == "Manchester") {
        longDest = 53.4808;
        latDest =  2.2426;
    } else if (addr == "Birmingham") {
        longDest = 52.4862;
        latDest =  1.8904;
    } else if (addr == "Edinburgh") {
        longDest = 55.9533;
        latDest =  3.1883;
    }

    double dLat = (latSource - latDest) *
                  M_PI / 180.0;
    double dLon = (longSource - longDest) *
                  M_PI / 180.0;

    // convert to radians
    latDest = (latDest) * M_PI / 180.0;
    latSource = (latSource) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(latDest) * cos(latSource);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    double distanceKilometers = rad * c;

    double finalShippingCost = ((distanceKilometers/2) * (weight) * (width * length * height));
    finalShippingCost = finalShippingCost / 100;
    finalShippingCost = std::ceil(finalShippingCost * 100.0) / 100.0;
    return finalShippingCost;
}


