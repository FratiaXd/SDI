//
// Created by fratia on 1/21/22.
//

/** @file forwarder.h
 *  @brief Child class of user class representing all information about forwarder
 *
 *  @author Katrina Petreikyte (fratiaxd)
 */

#ifndef SDI_APP_FORWARDER_H
#define SDI_APP_FORWARDER_H

#include "string"
#include "user.h"
using namespace std;

class Forwarder : public User {
public:
    /** @brief Default constructor
     *
     */
    Forwarder();

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
    Forwarder(string u, string p, string f_n, string em, string num, string t, string a);
};

#endif //SDI_APP_FORWARDER_H
