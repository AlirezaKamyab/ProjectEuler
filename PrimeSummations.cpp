// Created in 12/3/2022 by Alireza Kamyab
#include <iostream>
using namespace std;

constexpr int PRIMES = 25;

bool isPrime(const int&);
int primes[PRIMES];

int main() {
    primes[0] = 2;
    int counter = 1;
    int num = 3;
    while(counter < PRIMES) {
        if(isPrime(num)) primes[counter++] = num;
        num++;
    }

    int** dp = new int*[primes[PRIMES - 1]];
    for(int i = 0; i < primes[PRIMES - 1]; i++) dp[i] = new int[PRIMES] {0};

    for(int j = 0; j < PRIMES; j++) {
        dp[0][j] = 1;
    }

    for(int i = 1; i < primes[PRIMES - 1]; i++) {
        int j = 0;
        for(; j < PRIMES; j++) {
            if(j > 0) dp[i][j] = dp[i][j - 1];
            else dp[i][j] = 0;
            if(i - primes[j] >= 0) dp[i][j] += dp[i - primes[j]][j];
        }
        
        if(dp[i][j - 1] > 5000) {
            cout << "Answer is " << i << " with " << dp[i][j - 1] << " ways!" << endl;
            break;
        }
    }

    for(int i = 0; i < primes[PRIMES - 1]; i++) delete[] dp[i];
    delete[] dp;
    return 0;
}


bool isPrime(const int& number) {
    if(number <= 1) return false;
    if(number < 4) return true;
    if(number % 2 == 0) return false;
    if(number < 9) return true;
    if(number % 3 == 0) return  false;

    int counter = 1;
    int limit = 0;
    while(limit * limit <= number) {
        limit = 6 * counter;
        if(number % (limit + 1) == 0) return false;
        if(number % (limit - 1) == 0) return false;
        counter++;
    }
    return true;
}