// This file is written by Alireza Kamyab 5/5/2021
// Answer to proble projecteuler.net/problem=45
#include <iostream>
#include <cmath>
#include <cstdint>
using namespace std;

bool isTriangular(uint64_t t);
bool isPentagonal(uint64_t p);
bool isHexagonal(uint64_t h);
uint64_t hexagonal(int n);
uint64_t triangular(int n);
uint64_t pentagonal(int n);

int main(){
    for(int i = 144; true; i++){
        uint64_t hex = hexagonal(i);
        if(isPentagonal(hex) && isTriangular(hex)){
            cout << hex << endl;
            return 0;
        }
    }
    return 0;
}

bool isTriangular(uint64_t t){
    uint64_t delta = 1 + (8 * t);

    float root = ((-1) + sqrt(delta)) / (2);
    if((int)root == root) return true;
    else return false;
}

bool isPentagonal(uint64_t p){
    uint64_t delta = 1 + (24 * p);

    double root = ((1) + sqrt(delta)) / (6);
    if((int)root == root) return true;
    else return false;
}

bool isHexagonal(uint64_t h){
    uint64_t delta = 1 + (8 * h);

    double root = ((1) + sqrt(delta)) / (4);
    if((int)root == root) return true;
    else return false;
}

uint64_t hexagonal(int n){
    return n * ((2 * n) - 1);
}

uint64_t triangular(int n){
    return (n * (n + 1)) / 2;
}

uint64_t pentagonal(int n){
    return (n * ((3 * n) - 1)) / 2;
}