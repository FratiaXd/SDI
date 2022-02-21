//
// Created by fratia on 1/21/22.
//

/** @file transp_company.h
 *  @brief Child class of user class representing all information about the company
 *
 *  @author Katrina Petreikyte (fratiaxd)
 */


#ifndef SDI_APP_TRANSP_COMPANY_H
#define SDI_APP_TRANSP_COMPANY_H

#include "string"
#include "user.h"
using namespace std;

class TranspCompany : public User {
public:
    /** @brief Default constructor
     *
     */
    TranspCompany();

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
    TranspCompany(string u, string p, string f_n, string em, string num, string t, string a);
    double calculate_comission();
    void offer_driver();
};

#endif //SDI_APP_TRANSP_COMPANY_H
