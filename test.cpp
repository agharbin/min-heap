#include "minheap.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

bool test_insert() {
    minheap h;

    int key;
    for(int i = 0; i < 100; ++i) {
        key = rand() % 1000;
        h.insert(key,key);
    }

    std::vector<int> list;
    while(!h.empty()) {
        int item = h.pop();
        list.push_back(item);
    }

    if(std::is_sorted(list.begin(), list.end())) {
        return true;
    } else {
        return false;   
    }
}

bool test_reduce_key() {
    minheap h;

    h.insert(1,15);
    h.insert(2,14);
    h.insert(3,13);
    h.insert(4,12);
    h.insert(5,11);

    h.reduce_key(1,1);
    h.reduce_key(2,2);
    h.reduce_key(3,3);
    h.reduce_key(4,4);
    h.reduce_key(5,5);

    std::vector<int> list;
    while(!h.empty()) {
        int item = h.pop();
        list.push_back(item);
    }
    if(std::is_sorted(list.begin(), list.end())) {
        return true;
    } else {
        return false;   
    }
}

void run_test(std::string name, bool result) {
    if(result == true) {
        std::cout << name << " : " << "Passed" << std::endl;
    } else {
        std::cout << name << " : " << "Failed" << std::endl;
    }
}

int main(int argc, char ** argv) {
    run_test("Insert", test_insert());
    run_test("Reduce Key", test_reduce_key());

    return 0;
}
