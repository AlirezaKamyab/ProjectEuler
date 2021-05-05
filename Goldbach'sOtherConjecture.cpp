// This file is written by Alireza Kamyab 5/5/2021
// Answer to problem projecteuler.net/problem=46
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int number);
int previousPrime(int number);
bool doesFollowTheRule(int odd);

int main(){
    for(int i = 9; true; i += 2){
        if(!doesFollowTheRule(i)){
            if(isPrime(i)) continue;
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}

bool doesFollowTheRule(int odd){
    int prime = previousPrime(odd);
    while (prime != -1)
    {
        double n = sqrt(static_cast<double>(odd - prime) / 2);
        if((int)n == n) return true;
        prime = previousPrime(prime);
    }

    return false;
}

int previousPrime(int number){
    for(int i = number - 1; i > 1; i--){
        if(isPrime(i)) return i;
    }
    return -1;
}

bool isPrime(int number){
    if(number <= 1) return false;
    if(number < 4) return true;
    if(number % 2 == 0) return false;
    if(number < 9) return true;
    if(number % 3 == 0) return false;

    int counter = 1;
    int limit = 0;
    while(limit * limit <= number){
        limit = counter * 6;
        if(number % (limit - 1) == 0) return false;
        if(number % (limit + 1) == 0) return false;
        counter++;
    }

    return true;
}
