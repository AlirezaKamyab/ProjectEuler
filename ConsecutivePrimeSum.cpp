// This file is written by AlirezaKamyab 5/7/2021
// Answer to problem projecteuler.net/problem=50
// Using https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Overview
#include <iostream>
#include <cstdint>
using namespace std;

bool* primeArray(int limit);
bool isPrime(bool* arr, uint64_t number);
int nextPrime(bool* arr, int number, int limit);
void generatePrimeConsecutive(bool* arr, int initiate, int limit, int& maxStage, uint64_t& longestConsecutive);
void findLongestConsecutivePrime(bool* arr, int limit, int& count, uint64_t& longestConsecutive);

int main(){
    const int n = 1000000;
    bool* primes = primeArray(n);
    int count = 0;
    uint64_t longestConsecutive = 0;
    findLongestConsecutivePrime(primes, n, count, longestConsecutive);
    cout << "Max stage is " << count << " Longest consecutive is " << longestConsecutive << endl;
    return 0;
}

void findLongestConsecutivePrime(bool* arr, int limit, int& count, uint64_t& longestConsecutive){
    int counter = 2;
    while (counter < limit){
        generatePrimeConsecutive(arr, counter, limit, count, longestConsecutive);
        counter = nextPrime(arr, counter, limit);
    }
}

void generatePrimeConsecutive(bool* arr, int initiate, int limit, int& maxStage, uint64_t& longestConsecutive){
    int stage = 1;
    int counter = initiate;
    uint64_t sum = counter;

    while (sum <= limit){
        counter = nextPrime(arr, counter, limit);
        sum += counter;
        stage++;

        if (sum > limit) {
            return;
        }
        if (stage > maxStage && isPrime(arr, sum)){
            maxStage = stage;
            longestConsecutive = sum;
        }
    }
}

int nextPrime(bool* arr, int number, int limit){
    for(int i = number + 1; true; i++){
        if(i > limit) return limit + 1;
        if (isPrime(arr, i)) return i;
    }

    return 0; // Never is going to be called
}

bool isPrime(bool* arr, uint64_t number){
    return arr[number];
}

bool* primeArray(int limit){
    bool* arr = new bool[limit + 1];
    for(int i = 0; i < limit + 1; i++) arr[i] = true;
    arr[0] = false;
    arr[1] = false;

    for(int i = 2; i * i <= limit; i++){
        if (arr[i] == false) continue;
        for(int j = i * i; j <= limit; j += i){
            arr[j] = false;
        }
    }

    return arr;
}