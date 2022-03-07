//
// Created by fratia on 1/21/22.
//
#include "headers/transp_company.h"

using namespace std;

TranspCompany::TranspCompany() {

}

TranspCompany::TranspCompany(string u, string p, string f_n, string em, string num, string t, string a) {
    username = u;
    password = p;
    full_name = f_n;
    email = em;
    mobile = num;
    type = t;
    address = a;
}

vector<TranspCompany> TranspCompany::request_companies() {
    connection C("dbname = postgres user = postgres password = kek228 hostaddr = 127.0.0.1 port = 5432");
    if (C.is_open()) {
        cout << "Opened database successfully: " << C.dbname() << endl;
    }
    else {
        cout << "Can't open database" << endl;
    }
    string sql = "SELECT USERNAME, FULLNAME, EMAIL, MOBILE, ADDRESS FROM USERS WHERE TYPE = 'transportation company'";

    nontransaction N(C);

    result R(N.exec(sql));

    vector <TranspCompany> l1;

    for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
        string usern = decrypt(c[0].as<string>());
        string fulln = decrypt(c[1].as<string>());
        string emai = decrypt(c[2].as<string>());
        string mob = decrypt(c[3].as<string>());
        string addr = decrypt(c[4].as<string>());
        TranspCompany t1(usern, "", fulln, emai, mob, "", addr);
        l1.push_back(t1);
    }
    return l1;
}

double TranspCompany::calculate_comission(double fullPrice) {

}

void TranspCompany::offer_driver() {

}

