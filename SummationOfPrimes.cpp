// This file is written by Alireza Kamyab
// Answer to problem projecteuler.net/problem=10
#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

bool* listOfPrimes(int limit);

int main(){
    int limit = 2000000;
    uint64_t summation = 2;
    bool* primes = listOfPrimes(limit);

    for(int i = 1; i <= (limit - 1) / 2; i += 1){
        if(primes[i] == false){
            summation += 2 * i + 1;
        }
    }

    cout << summation << endl;
    return 0;
}

bool* listOfPrimes(int limit){
    int sieveBound = (limit - 1) / 2;
    bool* primeList = new bool[sieveBound] {0};
    int crossLimit = (floor(sqrt(limit)) - 1) / 2;

    for(int i = 1; i <= crossLimit; i += 1){
        if(primeList[i] == true) continue;

        for(int j = 2 * i * (i + 1); j <= sieveBound; j += 2 * i + 1){
            primeList[j] = true;
        }
    }

    return primeList;
}