// This file is written by Alireza Kamyab
// Answer to projecteuler.net/problem=55
#include <iostream>
#include <cinttypes>
#include <ctime>
using namespace std;

uint64_t reverse(uint64_t number);
bool isPalindromic(uint64_t number);
bool isLychrel(const uint64_t& number);

int main() {
    int count = 0;
    for(int i = 1; i < 10000; i++){
        if(isLychrel(i)) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}

bool isLychrel(const uint64_t& number){
    uint64_t temp = number + reverse(number);
    for(int i = 0; i < 50; i++) {
        if(isPalindromic(temp)) return false;
        temp = temp + reverse(temp);
    }
    return true;
}

bool isPalindromic(uint64_t number) {
    if(number == reverse(number)) return true;
    else return false;
}

uint64_t reverse(uint64_t number) {
    uint64_t temp = 0;
    while(number > 0) {
        temp = (temp * 10) + (number % 10);
        number /= 10;
    }
    return temp;
}