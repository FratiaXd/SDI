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

    /** @brief Parametrized constructor
     *
     * @param d cargo ID
     * @param f status
     * @param e cargo weight
     * @param r cargo height
     * @param h cargo width
     * @param yt cargo length
     * @param fr cargo type
     * @param ds source
     * @param dd destination
     * @param sdv shipping cost
     */
    Cargo(string d, string f, string e, string r, string h,string yt, string fr, string ds, string dd, string sdv);

    /** @brief Checks if cargo exists
     *
     * @return true if it exists/ false if not
     */
    bool cargo_exists();

    /** @brief Encryption
     *
     * @param value which is passed to be encrypted
     * @return encrypted value
     */
    string encrypt(string value);

    /** @brief Decryption
     *
     * @param value which is passed to be decrypted
     * @return decrypted value
     */
    string decrypt(string value);

    /** @brief
     *
     * @param w width
     * @param h height
     * @param wi width
     * @param leng length
     * @param t type
     * @param s source
     * @param d destination
     * @param cost shipping cost
     */
    void set_primary_values(string w, string h, string wi, string leng, string t, string s, string d, string cost);

    /** @brief Generates ID number for cargo
     * Starts from 100
     *
     * @return ID value
     */
    string generate_id();

    /** @brief Updates cargo shipment status
     *
     * @param currentStatus value to be set
     */
    void update_status(string currentStatus);

    void update_db_status(string newStatus, string actor, string usernm);

    /** @brief Assign transportation company to the cargo
    *
    * @param dri company's username
    */
    void assign_company(string com);

    /** @brief Assign driver to the cargo
    *
    * @param forw driver's username
    */
    void assign_driver(string dri);

    /** @brief Assign forwarder to the cargo
    *
    * @param own forwarder's username
    */
    void assign_forwarder(string forw);

    /** @brief Assign cargo owner to the cargo
     *
     * @param own cargo owner's username
     */
    void assign_owner(string own);

    /** @brief Assign receiver to the cargo
     *
     * @param rec receiver's username
     */
    void assign_receiver(string rec);

    /** @brief Saves cargo details to the database
     *
     */
    void savetoDB();

    /** @brief Checks if the user has done any orders
     *
     * @param unm username
     * @param actor user type
     * @return
     */
    bool has_any_orders(string unm, string actor);

    /** @brief Pulls list of user orders from database
     *
     * @param column user type column
     * @param val username
     * @return
     */
    list<Cargo> request_history(string column, string val);

    /** @brief Pulls list of user orders from database
     *
     * @param column column in the database
     * @param val value to look for in the column
     * @param type user type column
     * @param actor second user type
     * @param nm username
     * @return
     */
    list<Cargo> request_offers(string column, string val, string type, string actor, string nm);

    /** @brief Returns requested value
     *
     * @return cargo ID
     */
    string get_id();

    /** @brief Sets cargo id
     *
     * @param id new cargo ID
     */
    void set_id(string id);

    /** @brief Returns requested value
     *
     * @return status
     */
    string get_status();

    /** @brief Returns requested value
     *
     * @return weight
     */
    string get_weight();

    /** @brief Returns requested value
     *
     * @return height
     */
    string get_height();

    /** @brief Returns requested value
     *
     * @return width
     */
    string get_width();

    /** @brief Returns requested value
     *
     * @return length
     */
    string get_length();

    /** @brief Returns requested value
     *
     * @return type
     */
    string get_type();

    /** @brief Returns requested value
     *
     * @return source
     */
    string get_source();

    /** @brief Returns requested value
     *
     * @return destination
     */
    string get_destination();

    /** @brief Returns requested value
     *
     * @return forwarder
     */
    string get_forwarder();

    /** @brief Returns requested value
     *
     * @return owner
     */
    string get_owner();

    /** @brief Returns requested value
     *
     * @return company
     */
    string get_company();

    /** @brief Returns requested value
     *
     * @return shipping cost
     */
    string get_shippingCost();
};

#endif //SDI_APP_CARGO_H
