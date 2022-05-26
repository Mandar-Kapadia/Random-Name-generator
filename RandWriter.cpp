/*Copyright 2022  Mandar Kapadia */
#include"RandWriter.h"
RandWriter::RandWriter(std::string text, int k) {
    srand((int)time(NULL)); //NOLINT 
    order = k;
    std::string text2 = text;
    text2 += text[0];
    std::string temp;
    // check if k isnt negitive and is positive
    if (k < 0 || ((unsigned) k > text.length() )) {
        throw std::invalid_argument(" k cannot be smaller then 0 or greater the lenght"); //NOLINT
    }
    // made a loop that takes the substring from size and will put in hashmap
    for (unsigned int i = 0; i < text.length(); i++) {
        temp = text2.substr(i , k);
        char tempChar = text2[i + k];
        if (tempChar == '\0') {
            tempChar = text[0];
        }
        auto it = RandWriterMap.find(temp);
        if (temp.length() != (unsigned) k) {
            continue;
        } else if (it == RandWriterMap.end()) {
            RandWriterMap.insert({temp, std::map<char , int>()});
            RandWriterMap[temp].insert({tempChar , 1});
        } else if (it != RandWriterMap.end()) { //NOLINT
            RandWriterMap[temp][tempChar]+= 1; //NOLINT
        }
    }
}
int RandWriter::orderK() const {
    return order;
}
int RandWriter::freq(std::string kgram, char c) const {
    // return freq if errors does not happen
    auto tester = RandWriterMap.find(kgram);
    if ((unsigned)order != kgram.length()) {
        throw std::invalid_argument(" kgram is not k length"); //NOLINT
    }
    if (tester == RandWriterMap.end()) {
        throw std::invalid_argument(" kgram is not in the hashmaps");
    }
    auto tester2 = RandWriterMap.at(kgram).find(c);
        if (tester2 == RandWriterMap.at(kgram).end()) {
        throw std::invalid_argument(" c is not in the hashmap");
    }

    return(RandWriterMap.at(kgram).at(c));
}
int RandWriter::freq(std::string kgram) const {
    int counter = 0;
    auto tester = RandWriterMap.find(kgram);
    if ((unsigned)order != kgram.length()) {
        throw std::invalid_argument(" kgram is not k length"); //NOLINT
    }
    if (tester == RandWriterMap.end()) {
        throw std::invalid_argument(" kgram is not in the hashmap");
    }
    // adds all the values and return counter
    for(auto it = RandWriterMap.at(kgram).begin(); it != RandWriterMap.at(kgram).end(); it++) { //NOLINT
        counter += it->second;
    }
    return(counter);
}
char RandWriter::kRand(std::string kgram) {
    if ((unsigned)order != kgram.length()) {
        throw std::invalid_argument(" kgram is not k length"); //NOLINT
    }
    auto tester = RandWriterMap.find(kgram);
    if (tester == RandWriterMap.end()) {
        throw std::invalid_argument(" kgram is not in the array");
    }
    // get random values based of probs
    int kgramFreq = freq(kgram);
    int randNumber = rand() % kgramFreq; //NOLINT
    int totalProb = 0;
    for (auto itr = RandWriterMap[kgram].begin(); itr != RandWriterMap[kgram].end(); itr++ ) { //NOLINT
        totalProb += itr->second;
        if (randNumber <= totalProb) {
            return itr->first;
        }
    }
    return('\0');
}
std::string RandWriter::generate(std::string kgram, int L) {
    if (order > L) {
        throw std::invalid_argument(" l is not k length"); //NOLINT
    }
    if ((unsigned)order != kgram.length()) {
        throw std::invalid_argument(" kgram is not k length"); //NOLINT
    }
    auto tester = RandWriterMap.find(kgram);
    if (tester == RandWriterMap.end()) {
        throw std::invalid_argument(" kgram is not in the hashmap");
    }
    // return string that with kgrams
    std::string retString = kgram;
    // return char takes in krand chars
    char retChar;
    // forloop that goes L - korders and pushes that chars into the string
    for (int i = 0; i < (L - order); i++) {
        retChar = kRand(retString.substr(i , order));
        retString.push_back(retChar);
    }
    return retString;
}
std::ostream& operator<<(std::ostream& os, const RandWriter& dt) {
    // double for loop that prints all the value.
    for (auto itr = dt.RandWriterMap.begin(); itr != dt.RandWriterMap.end(); itr++) { //NOLINT
        os << itr->first << "\n-----------\n";
        for (auto ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
            os << ptr ->first << ":" << ptr ->second << "\n"; //NOLINT
        }
        os << "-----------\n\n";
    }
    return os;
}
