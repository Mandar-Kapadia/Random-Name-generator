/*Copyright 2022  Mandar Kapadia */
#include <boost/test/unit_test.hpp>//NOLINT
#include<iostream>//NOLINT
#include<map>//NOLINT
#include<ctime>//NOLINT
#include<cstdlib>//NOLINT
#include<string>//NOLINT
#include<exception>//NOLINT
#include<vector>//NOLINT
#include<algorithm>//NOLINT
class RandWriter {
 public:
    RandWriter(std::string text, int k);
    int orderK() const;
    int freq(std::string kgram) const;
    int freq(std::string kgram, char c) const;
    char kRand(std::string kgram);
    std::string generate(std::string kgram, int L);
    friend std::ostream& operator<<(std::ostream& os, const RandWriter& dt);
 private:
    std::map<std::string,std::map<char,int>> RandWriterMap;  //NOLINT
    int order;
};
