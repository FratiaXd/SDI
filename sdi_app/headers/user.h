//
// Created by fratia on 1/21/22.
//

/** @file user.h
 *  @brief Parent class of all other classes (except cargo) representing all common user information
 *  Also is considered as a receiver actor
 *
 *  @author Katrina Petreikyte (fratiaxd)
 */

#ifndef SDI_APP_USER_H
#define SDI_APP_USER_H

#include "string"
#include <pqxx/pqxx>
using namespace std;

class User {
protected:
    string username;    /*!< a string value */
    string password;    /*!< a string value */
    string full_name;   /*!< a string value */
    string email;       /*!< a string value */
    string mobile;      /*!< a string value */
    string type;        /*!< a string value */
    string address;     /*!< a string value */
public:
    /** @brief Default constructor
     *
     */
    User();

    /** @brief Paramerized constructor
     *
     * @param u username
     * @param p password
     * @param f_n full name
     * @param em email
     * @param num phone number
     * @param t user type
     * @param a address
     */
    User(string u, string p, string f_n, string em, string num, string t, string a);

    /** @brief Sets user type to m
    *
    * @param m is string naming one of five actors
    */
    void set_type(string m);

    bool user_exists(string usernameToCompare);

    /** @brief Gets user type
     *
     * @return string naming one of five actors
     */
    string get_type();

    /** @brief Encrypts data
     *
     * @param value is a string to encrypt
     * @return encrypted string
     */
    string encrypt(string value);

    /** @brief Decrypts data
     *
     * @param value is a string to decrypt
     * @return decrypted string
     */
    string decrypt(string value);

    /** @brief Sets just username of an object
     *
     * @param u is a string to be set as a username
     */
    void set_n(string u);

    /** @brief Accesses just a username of an object
     *
     * @return username
     */
    string get_n();

    string get_fulln();

    string get_email();

    string get_mobile();

    string get_address();
    /** @brief Connects to the database and saves user details in there
     */
    void registration();

    /** @brief Connects to the database and compares the details provided by the user to details in the database
     *
     * @param usnm username provided by user
     * @param psswrd password provided by user
     * @return true if the user exists in the database, false if does not
     */
    bool sign_in(string usnm, string psswrd);

    /** @brief Connects to the database and determines the user type according to his username
     *
     * @param usn username
     * @return integer value to open appropriate menu
     */
    int open_menu(string usn);
};

#endif //SDI_APP_USER_H
