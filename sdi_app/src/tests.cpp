#define BOOST_TEST_MODULE SDITestModule
#include <boost/test/included/unit_test.hpp>

#include "headers/cargo.h"
#include "headers/user.h"

BOOST_AUTO_TEST_CASE(cargoTests){
    Cargo newCargo("id","status","5","5","5","5","fragile","Nottingham","Birmingham","123");
    BOOST_CHECK_EQUAL(newCargo.get_id(),"id");
    BOOST_CHECK_EQUAL(newCargo.get_status(),"status");
    BOOST_CHECK_EQUAL(newCargo.get_weight(),"5");
    BOOST_CHECK_EQUAL(newCargo.get_height(),"5");
    BOOST_CHECK_EQUAL(newCargo.get_width(),"5");
    BOOST_CHECK_EQUAL(newCargo.get_length(),"5");
    BOOST_CHECK_EQUAL(newCargo.get_type(),"fragile");
    BOOST_CHECK_EQUAL(newCargo.get_destination(),"Nottingham");
    BOOST_CHECK_EQUAL(newCargo.get_shippingCost(),"123");

    BOOST_CHECK(newCargo.encrypt("abc") != "abc");
    BOOST_CHECK(newCargo.decrypt(newCargo.encrypt("abc")) == "abc");

}

BOOST_AUTO_TEST_CASE(userTests){
    User newUser("username","pass","FullName","email@example.com","123456","forwarder","Nottingham");
    BOOST_CHECK_EQUAL(newUser.get_n(),"username");
    BOOST_CHECK_EQUAL(newUser.get_fulln(),"FullName");
    BOOST_CHECK_EQUAL(newUser.get_email(),"email@example.com");
    BOOST_CHECK_EQUAL(newUser.get_mobile(),"123456");
    BOOST_CHECK_EQUAL(newUser.get_type(),"forwarder");
    BOOST_CHECK_EQUAL(newUser.get_address(),"Nottingham");

    newUser.set_n("user2");
    BOOST_CHECK_EQUAL(newUser.get_n(),"user2");

    newUser.set_type("driver");
    BOOST_CHECK_EQUAL(newUser.get_type(),"driver");
}
