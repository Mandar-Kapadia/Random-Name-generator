/*Copyright 2022  Mandar Kapadia */
#include<iostream>
#include "RandWriter.h"
void testingArc(bool(*func)(int argc), int argc);
int main(int argc, char* argv[]) {
    // throw an error if there isnt 3 arguments
    testingArc(([](int argc){ return (argc != 3);}) , argc);
    std::string kString = argv[1];
    std::string lString = argv[2];
    int k = std::stoi(kString);
    int l = std::stoi(lString);

    // get lines to make a big string
    std::string inputText = "";
    std::string totalFileString = "";

    while (std::cin >> inputText) {
        totalFileString += " " + inputText;
    }

    RandWriter temp(totalFileString , k);
    std::cout << temp.generate(totalFileString.substr(0 , k) , l);

    return 0;
}
void testingArc(bool(*func)(int argc), int argc) {
    if (func(argc)) {
         std::runtime_error("need 3 arguments");
    }
}
