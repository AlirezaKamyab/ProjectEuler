// This file is written by Alireza Kamyab
// Answer to problem projecteuler.net/problem=51
#include <iostream>
using namespace std;

bool isPrime(const int& number);
int step(int number, const int& digit = 0);
int minForEveryDigit(const int& digit);

const int LIMIT = 10000000;
const int MAX_COUNT = 8;

int main() {
    int min = LIMIT;
    for(int i = 0; i <= 9 - MAX_COUNT; i++){
        int result = minForEveryDigit(i);
        min = (result < min)? result : min;
    }

    cout << min << endl;
    return 0;
}

int minForEveryDigit(const int& digit) {
    for(int i = 0; i < LIMIT; i++) {
        int s = step(i, digit);

        if(s == 0) continue;
        if(!isPrime(i)) continue;

        int temp = i + s;
        int min = i;
        int primeCounter = 1;

        for(int j = 1; j <= 9 - digit; j++) {
            if(isPrime(temp)) {
                primeCounter++;
            }
            temp += s;
        }

        if(primeCounter == MAX_COUNT) {
            return min;
        }
    }

    return -1;
}

int step(int number, const int& digit) {
    int multiplier = 1;
    int result = 0;

    while (number > 0) {
        int r = number % 10;
        if (r == digit) result += multiplier;
        multiplier *= 10;
        number /= 10;
    }

    return result;
}

bool isPrime(const int& number) {
    if (number <= 1) return false;
    if (number < 4) return true;
    if (number % 2 == 0) return false;
    if (number < 9) return true;
    if (number % 3 == 0) return false;

    int counter = 1;
    int limit = 0;
    while (limit * limit <= number) {
        limit = counter * 6;
        if (number % (limit - 1) == 0) return false;
        if (number % (limit + 1) == 0) return false;
        counter++;
    }

    return true;
}