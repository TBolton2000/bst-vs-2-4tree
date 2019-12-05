#include"testing.h"

void ReturnTiming::test_increasing(int size) {
    BinarySearchTree<int,int> incTree;
    clear();
    std::cout << "Running test for insert increasing" << std::endl;
    for(int i = 0; i < size; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        incTree.insert(i,i);
        if(i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
            auto end = std::chrono::high_resolution_clock::now();
            double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            addInsData(i,duration);
        }
    }
    std::cout << "Completed Test for insert increasing" << std::endl;
    std::cout << std::endl << "Running test for remove increasing" << std::endl;
    for(int i = 0; i < size-4; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        incTree.remove(i);
        if(i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
            auto end = std::chrono::high_resolution_clock::now();
            double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            addRemData(i,duration);
        }
    }
    std::cout << "Completed Test for remove increasing" << std::endl;
}

void ReturnTiming::test_decreasing(int size) {
    BinarySearchTree<int,int> decTree;
    clear();
    std::cout << "Running test for insert decreasing" << std::endl;
    for(int i = 0; i < size; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        decTree.insert(size-i,size-i);
        if(i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
            auto end = std::chrono::high_resolution_clock::now();
            double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            addInsData(i,duration);
        }
    }
    std::cout << "Completed Test for insert decreasing" << std::endl;
    std::cout << std::endl << "Running test for remove decreasing" << std::endl;
    for(int i = 0; i < size-4; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        decTree.remove(size-i);
        if(i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
            auto end = std::chrono::high_resolution_clock::now();
            double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            addRemData(i,duration);
        }
    }
    std::cout << "Completed Test for remove decreasing" << std::endl;
}

void ReturnTiming::test_random(int size) {
    srand(120);
    BinarySearchTree<int,int> randTree;
    clear();
    std::vector<int> insBag;
    std::vector<int> remBag;
    for(int i = 0; i < size; i++) {
        insBag.push_back(i);
        remBag.push_back(i);
    }
    std::cout << "Running test for insert random" << std::endl;
    for(int i = 0; i < size; i++) {
        int index = std::rand() % insBag.size();
        int toInsert = insBag.at(index);
        insBag.erase(insBag.begin()+index);
        auto start = std::chrono::high_resolution_clock::now();
        randTree.insert(toInsert,toInsert);
        if(i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
            auto end = std::chrono::high_resolution_clock::now();
            double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            addInsData(i,duration);
        }
    }
    std::cout << "Completed Test for insert random" << std::endl;
    std::cout << std::endl << "Running test for remove random" << std::endl;
    for(int i = 0; i < size-7; i++) {
        int index = (std::rand() % 1000000000 % remBag.size());
        int toRemove = remBag.at(index);
        remBag.erase(remBag.begin()+index);
        auto start = std::chrono::high_resolution_clock::now();
        randTree.remove(i);
        if(i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
            auto end = std::chrono::high_resolution_clock::now();
            double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            addRemData(i,duration);
        }
    }
    std::cout << "Completed Test for remove random" << std::endl;
}