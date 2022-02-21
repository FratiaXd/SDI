//
// Created by fratia on 1/21/22.
//

/** @file cargo.h
 *  @brief Class representing all information about cargo's sent by users
 *
 *  @author Katrina Petreikyte (fratiaxd)
 */

#ifndef SDI_APP_CARGO_H
#define SDI_APP_CARGO_H

#include "string"
#include <pqxx/pqxx>
#include "iostream"
using namespace std;

class Cargo {
protected:
    string cargoID;         /*!< a string value */
    string status;          /*!< a string value */
    string weight;          /*!< a string value */
    string height;          /*!< a string value */
    string width;           /*!< a string value */
    string length;          /*!< a string value */
    string type;            /*!< a string value */
    string source;          /*!< a string value */
    string destination;     /*!< a string value */
    string shippingCost;    /*!< a string value */
    string owner;           /*!< a string value */
    string forwarder;       /*!< a string value */
    string company;         /*!< a string value */
    string drver;           /*!< a string value */
    string receiver;        /*!< a string value */
public:
    /** @brief Default constructor
     *
     */
    Cargo();

    Cargo(string d, string f, string e, string r, string h,string yt, string fr, string ds, string dd, string sdv);
    bool cargo_exists();
    string encrypt(string value);
    string decrypt(string value);
    void set_primary_values(string w, string h, string wi, string leng, string t, string s, string d, string cost);
    string generate_id();
    void update_status(string currentStatus);
    void assign_owner(string own);
    void assign_forwarder(string forw);
    void assign_driver(string dri);
    void assign_company(string com);
    void assign_receiver(string rec);
    void savetoDB();
    bool has_any_orders(string unm, string actor);
    list<Cargo> request_history(string user, string actor);
    string get_id();
    string get_status();
    string get_weight();
    string get_height();
    string get_width();
    string get_length();
    string get_type();
    string get_source();
    string get_destination();
    string get_shippingCost();
};

#endif //SDI_APP_CARGO_H
