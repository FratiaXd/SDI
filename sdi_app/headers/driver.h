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
    string currentPos;      /*!< a string value */
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

    /** @brief Saves driver's lorry details
     *
     * @param ni NI number
     * @param lid lorry ID
     * @param tp type of lorry
     * @param reg lorry registration number
     * @param he lorry height
     * @param wi lorry width
     * @param le lorry length
     * @param we lorry weight
     * @param cpc lorry's cpc number
     */
    void driver_details(string ni, string lid, string tp, string reg, string he, string wi, string le, string we, string cpc, string currLocation);

    /** @brief saves driver's data into the database
     *
     */
    void registration_driver();

    /** @brief Validates lorry's cpc number
     *
     * @param cpcNumber cpc number
     *
     * @return true if lorry is appropriate/ false not appropriate
     */
    bool check_cpc(string cpcNumber);

    /** @brief sets new driver's position
     *
     * @param newPosition position to set
     */
    void update_position(string newPosition);

    /** @brief updates driver's position in the database
     *
     */
    void update_positionDB();

    /** @brief Validates lorry's registration number with use of API
     *
     * @param regNumber registration number
     *
     * @return true if number is appropriate/ false not appropriate
     */
    bool check_regnum(string regNumber);

    /** @brief requests all existing users with the type driver
     *
     * @return vector of existing drivers
     */
    vector<Driver> request_drivers();

    /** @brief requests for current driver's location
     *
     * @return driver's location
     */
    string get_location();

    /** requests for current driver's location from the database
     *
     * @return driver's location from the database
     */
    string request_locationDB();
};

#endif //SDI_APP_DRIVER_H
