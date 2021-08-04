// This file is written by Alireza Kamyab
// Answer to problem projecteuler.net/problem=51
#include <iostream>
using namespace std;

bool isPrime(const int& number);
int step(int number, const int& digit = 0);
int minForEveryDigit();

const int LIMIT = 10000000;
const int MAX_COUNT = 8;

int main() {
    int result = minForEveryDigit();
    cout << result << endl;
    return 0;
}

int minForEveryDigit() {
    for(int i = 0; i < LIMIT; i++) {
        int s = step(i, 1);

        if(s == 0) continue;

        int primeCounter = 0;
        int temp = (isPrime(i - s) && s < i - s)? i - s : i; // If 56113 is found, can we start from 56001?

        int min = temp + (10 * s);

        // If for instance we start from 56113 we have left 56001, so one iteration is completed else we iterate 10 times
        for(int j = (temp == i)? 1 : 0; j <= 9; j++) {
            if(isPrime(temp)) {
                min = (temp < min)? temp : min;
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