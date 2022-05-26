/*Copyright 2022  Mandar Kapadia */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include"RandWriter.h"

BOOST_AUTO_TEST_CASE(construtor) {
    BOOST_REQUIRE_THROW(RandWriter("string", -5) , std::invalid_argument);
    BOOST_REQUIRE_THROW(RandWriter("4", 2) , std::invalid_argument);
    RandWriter temp("string", 0);
    BOOST_REQUIRE(temp.orderK() == 0);
}
BOOST_AUTO_TEST_CASE(size) {
    RandWriter temp("string", 0);
    BOOST_REQUIRE(temp.orderK() == 0);
}
BOOST_AUTO_TEST_CASE(freq) {
    RandWriter temp("gagggagaggcgagaaa", 0);
    std::cout << temp;
    BOOST_REQUIRE(temp.freq("") == 17);
    BOOST_REQUIRE(temp.freq("" , 'c') == 1);
     RandWriter temp2("gagggagaggcgagaaa", 3);
     std::cout << temp2;
}
BOOST_AUTO_TEST_CASE(krand) {
    RandWriter temp("gagggagaggcgagaaa", 1);
    BOOST_REQUIRE_THROW(temp.kRand("aaa") , std::invalid_argument);
    BOOST_REQUIRE_THROW(temp.kRand("f") , std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(generate) {
    RandWriter temp("gagggagaggcgagaaa", 1);
    BOOST_REQUIRE_THROW(temp.generate("aaa", 10) , std::invalid_argument);
    BOOST_REQUIRE_THROW(temp.generate("f", 10) , std::invalid_argument);
    BOOST_REQUIRE_THROW(temp.generate("c", 0) , std::invalid_argument);
}
