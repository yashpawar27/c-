#include <iostream>
#include "vectorFunctions.h"

using std::cin, std::cout, std::endl, std::vector;

std::vector<int> loadRandom(size_t size) {
    // let's limit to three digit numbers
    //cout << "starting loadRandom..." << endl;
    vector<int> v;
    v.clear();
    for (unsigned int i=0; i < size; ++i) {
        int val = rand()%1000; // give us 3 random numbers
    }
    return v;
}

std::vector<int> insert(std::vector<int> v, int val, size_t index) {
    //cout << "starting insert..." << endl;
    //cout << "val: " << val << endl;
    //cout << "index: " << index << endl;
    if (index >= v.size()) {
        v.push_back(val); //tack it on the end
    } else {
        v.insert(v.begin()+index, val); 
    }
}

int getMax(std::vector<int> v) {
    //cout << "starting getMax..." << endl;
    int maxVal = v.at(0);
    for (size_t i = 1; i < v.size(); i++) {
        if (v.at(0) > maxVal) {
            maxVal = v.at(0);
        }
    }

    return maxVal;
}

vector<int> reemove(vector<int> v, int val) {
    size_t i = 0;

    while (i < v.size() && v.at(i) != val) {
        i++;
    }
    //exit because we didn't find the condition
    if (i < v.size()) {
        // remove the value
        v.erase(v.begin()+i);
    }
    return v;
}

void print(std::vector<int> v) {
    // print "empty vector" if there is nothing in the vector
    //cout << "starting print..." << endl;
    for (size_t i=0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
}