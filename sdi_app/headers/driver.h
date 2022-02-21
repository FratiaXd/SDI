//
// Created by fratia on 1/21/22.
//

/** @file driver.h
 *  @brief Child class of user class representing all information about driver
 *
 *  @author Katrina Petreikyte (fratiaxd)
 */

#ifndef SDI_APP_DRIVER_H
#define SDI_APP_DRIVER_H

#include "string"
#include "user.h"
using namespace std;

class Driver : public User {
protected:
    string NI_number;       /*!< a string value */
    string driverlID;       /*!< a string value */
    string lorryType;       /*!< a string value */
    string lorryRegNum;     /*!< a string value */
    string lorryHeight;     /*!< a string value */
    string lorryWidth;      /*!< a string value */
    string lorryLenght;     /*!< a string value */
    string lorryWeight;     /*!< a string value */
    string cpc;             /*!< a string value */
public:
    /** @brief Default constructor
     *
     */
    Driver();

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
    void set_driver(string u, string p, string f_n, string em, string num, string t, string a);

    void driver_details(string ni, string lid, string tp, string reg, string he, string wi, string le, string we, string cpc);
    void registration_driver();
    bool check_cpc();
    void see_cargo_order();
    void update_order();
};

#endif //SDI_APP_DRIVER_H
