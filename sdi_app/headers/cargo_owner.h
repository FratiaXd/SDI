//
// Created by fratia on 1/21/22.
//

/** @file cargo_owner.h
 *  @brief Child class of user class representing all information about cargo owner
 *
 *  @author Katrina Petreikyte (fratiaxd)
 */

#ifndef SDI_APP_CARGO_OWNER_H
#define SDI_APP_CARGO_OWNER_H

#include "string"
#include "user.h"
using namespace std;

class CargoOwner : public User {
public:
    /** @brief Default constructor
     *
     */
    CargoOwner();


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
    CargoOwner(string u, string p, string f_n, string em, string num, string t, string a);

    /** @brief Calculates cargo shipping price according to its details
     *
     * @param w width
     * @param h height
     * @param l length
     * @param we weight
     * @param src source address
     * @param addr destination address
     * @return shipping price
     */
   double calculate_shipping(float w, float h, float l, float we, string src, string addr);

};

#endif //SDI_APP_CARGO_OWNER_H
