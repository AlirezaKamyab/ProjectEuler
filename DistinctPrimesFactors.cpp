// This file is written by Alireza Kamyab 5/5/2021
// Solution to problem projecteuler.net/problem=47
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int number);
int distinctPrimeFactors(int number);

int main(){
    const int n = 4;

    int number = 0;
    int consecutive = 0;
    for(int i = 134038; true; i++){
        if(distinctPrimeFactors(i) == n) {
            number = i;
            consecutive++;
        }
        else {
            consecutive = 0;
            continue;
        }

        if(consecutive == n){
            cout << number - n + 1<< endl; // Print out the first number
            break;
        }
    }
    return 0;
}

int distinctPrimeFactors(int number){
    int counter = 0;
    for(int i = 2; i * i <= number; i++){
        if(number % i == 0){
            int q = number / i;
            if(isPrime(i)) counter++;
            if(isPrime(q) && q != i) counter++;
        }
    }

    return counter;
}

bool isPrime(int number){
    if(number <= 1) return false;
    if(number < 4) return true;
    if(number % 2 == 0) return false;
    if(number < 9) return true;
    if(number % 3 == 0) return false;

    int counter = 1;
    int limit = 0;
    while(limit * limit < number){
        limit = counter * 6;
        if(number % (limit - 1) == 0) return false;
        if(number % (limit + 1) == 0) return false;
        counter++;
    }
    return true;
}