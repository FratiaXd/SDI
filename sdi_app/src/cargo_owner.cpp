//
// Created by fratia on 1/21/22.
//
#include "headers/cargo_owner.h"
#include <cmath>

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
    double longSource = 0, latSource = 0, longDest = 0, latDest = 0;
    double dLat = (latSource - latDest) *
                  M_PI / 180.0;
    double dLon = (longSource - longSource) *
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
    return finalShippingCost;



}

void CargoOwner::place_order() {

}

