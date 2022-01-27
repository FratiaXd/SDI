//
// Created by fratia on 1/21/22.
//
#include "string"
#include "user.h"

using namespace std;

#ifndef SDI_APP_TRANSP_COMPANY_H
#define SDI_APP_TRANSP_COMPANY_H

class TranspCompany : public User {
public:
    //TransCompany(string u, string p, string f_n, string em, string num, string t);
    double calculate_comission();
    void offer_driver();
};

#endif //SDI_APP_TRANSP_COMPANY_H
