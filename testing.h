#ifndef TESTING_H
#define TESTING_H

#include"BST.h"
#include<chrono>
#include<vector>
#include<utility>
#include<iostream>
#include<random>



class ReturnTiming {
    std::vector<int> numberIns;
    std::vector<double> timeIns;
    std::vector<int> numberRem;
    std::vector<double> timeRem;
public:
    ReturnTiming() {}

    void test_increasing(int size);
    void test_decreasing(int size);
    void test_random(int size);

    void clear() {
        numberIns.clear();
        timeIns.clear();
        numberRem.clear();
        timeRem.clear();
    }

    void addInsData(int num, double time) {
        numberIns.push_back(num);
        timeIns.push_back(time);
    }
    void addRemData(int num, double time) {
        numberRem.push_back(num);
        timeRem.push_back(time);
    }

    void printData() {
        std::cout << "Inserting" << std::endl;
        for(int i = 0; i < numberIns.size(); i++) {
            std::cout << numberIns.at(i) << "," << timeIns.at(i) << std::endl;
        }
        std::cout << "Removing" << std::endl;
        for(int i = 0; i < numberRem.size(); i++) {
            std::cout << numberRem.at(i) << "," << timeRem.at(i) << std::endl;
        }
    }
};

#endif /*TESTING_H*/