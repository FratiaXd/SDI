//
// Created by fratia on 1/21/22.
//
#include "headers/driver.h"
#include <pqxx/pqxx>
#include "iostream"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using namespace pqxx;
using namespace std;

Driver::Driver() {

}

void Driver::set_driver(string u, string p, string f_n, string em, string num, string t, string a) {
    username = u;
    password = p;
    full_name = f_n;
    email = em;
    mobile = num;
    type = t;
    address = a;
}

void Driver::driver_details(string ni, string lid, string tp, string reg, string he, string wi, string le, string we, string cp, string currLocation) {
    NI_number = ni;
    driverlID = lid;
    lorryType = tp;
    lorryRegNum = reg;
    lorryHeight = he;
    lorryWidth = wi;
    lorryLenght = le;
    lorryWeight = we;
    cpc = cp;
    currentPos = currLocation;
}

void Driver::registration_driver() {
    connection C("dbname = postgres user = postgres password = kek228 hostaddr = 127.0.0.1 port = 5432");
    if (C.is_open()) {
        cout << "Opened database successfully: " << C.dbname() << endl;
    }
    else {
        cout << "Can't open database" << endl;
    }

    string un = encrypt(username);
    string pw = encrypt(password);
    string f_nm = encrypt(full_name);
    string ema = encrypt(email);
    string mob = encrypt(mobile);
    string add = encrypt(address);
    string ni = encrypt(NI_number);
    string di = encrypt(driverlID);
    string lt = encrypt(lorryType);
    string lrg = encrypt(lorryRegNum);
    string he = encrypt(lorryHeight);
    string wi = encrypt(lorryWidth);
    string le = encrypt(lorryLenght);
    string we = encrypt(lorryWeight);
    string c = encrypt(cpc);
    string currentLoc = encrypt(currentPos);

    string sql = "INSERT INTO USERS(USERNAME, PASSWORD, FULLNAME, EMAIL, MOBILE, TYPE, ADDRESS," \
                 "NINUMBER, LICENSEID, LORRY_TYPE, REGISTRATION_NUM, L_HEIGHT, L_WIDTH, L_LENGHT, L_WEIGHT, CPC, LOCATION)" \
                 "VALUES('"+ un + "', '" + pw+ "', '" + f_nm + "', '" + ema + "', '" + mob + "', '" + type + "', '" + add + "', '" \
                 + ni + "', '" + di + "', '" + lt + "', '" + lrg + "', '" + he + "', '" + wi + "', '" + le + "', '" + we + "', '" + c + "', '" + currentLoc + "');";

    work W(C);

    W.exec(sql);
    W.commit();
    cout << "User saved" << endl;
}

void Driver::update_position(string newPosition) {
    currentPos = newPosition;
}

void Driver::update_positionDB() {
    connection C("dbname = postgres user = postgres password = kek228 hostaddr = 127.0.0.1 port = 5432");
    if (C.is_open()) {
        cout << "Opened database successfully: " << C.dbname() << endl;
    }
    else {
        cout << "Can't open database" << endl;
    }

    string positionEncr = encrypt(currentPos);
    string usernameEncr = encrypt(username);

    string sql = "UPDATE users SET location = '" + positionEncr + "' WHERE username = '" + usernameEncr + "';";

    work W(C);
    W.exec( sql );
    W.commit();
}

bool Driver::check_cpc(string cpcNumber) {
    if (cpcNumber.length() == 6){
        return true;
    }
    else {
        return false;
    }
}

bool Driver::check_regnum(string regNumber) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    nlohmann::json body = {
            {"registrationNumber", regNumber}
    };
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, "https://driver-vehicle-licensing.api.gov.uk/vehicle-enquiry/v1/vehicles");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "x-api-key: 6mUEHLR1ju7Z8sMg927oa9TblqrMA7Xa1eI3da2o");
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        string bodyTest = body.dump();
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, bodyTest.c_str());
        res = curl_easy_perform(curl);
        if (res == 0) {
            return true;
        } else {
            return false;
        }
    }
}

vector<Driver> Driver::request_drivers() {
    connection C("dbname = postgres user = postgres password = kek228 hostaddr = 127.0.0.1 port = 5432");
    if (C.is_open()) {
        cout << "Opened database successfully: " << C.dbname() << endl;
    }
    else {
        cout << "Can't open database" << endl;
    }

    string sql = "SELECT USERNAME, FULLNAME, EMAIL, MOBILE, ADDRESS, LOCATION FROM USERS WHERE TYPE = 'driver'";

    nontransaction N(C);

    result R(N.exec(sql));

    vector <Driver> driverList;

    for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
        string usern = decrypt(c[0].as<string>());
        string fulln = decrypt(c[1].as<string>());
        string emai = decrypt(c[2].as<string>());
        string mob = decrypt(c[3].as<string>());
        string addr = decrypt(c[4].as<string>());
        string locat = decrypt(c[5].as<string>());
        Driver driverTemp;
        driverTemp.set_driver(usern, "", fulln, emai, mob, "", addr);
        driverTemp.update_position(locat);
        driverList.push_back(driverTemp);
    }
    return driverList;
}

string Driver::get_location() {
    return currentPos;
}

string Driver::request_locationDB() {
    connection C("dbname = postgres user = postgres password = kek228 hostaddr = 127.0.0.1 port = 5432");
    if (C.is_open()) {
        cout << "Opened database successfully: " << C.dbname() << endl;
    }
    else {
        cout << "Can't open database" << endl;
    }

    string usernEncr = encrypt(username);
    string currLocation;
    string sql = "SELECT LOCATION FROM USERS WHERE USERNAME = '" + usernEncr + "';";

    nontransaction N(C);

    result R(N.exec(sql));

    for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
        currLocation = decrypt(c[0].as<string>());
    }
    return currLocation;
}

