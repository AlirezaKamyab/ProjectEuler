// This file is written by AlirezaKamyab
// Answer to problem projecteuler.net/problem=12
#include <iostream>
#include <cmath>
using namespace std;

bool* primeList(int limit);
int divisorsCount(bool* primeList, int number);

int main(){
    int limit = 500; 
    bool* primes = primeList(1000);

    int n = 1;
    int n1 = n + 1;
    while (true)
    {
        int countN = divisorsCount(primes, (n % 2 == 0)? n / 2 : n); 
        int countN1 = divisorsCount(primes,  (n1 % 2 == 0)? n1 / 2 : n1);

        if(countN * countN1 >= limit){
            cout << n * (n1) / 2 << endl;
            return 0;
        }
        n++;
        n1 = n + 1;
    }
    
    return 0;
}

int divisorsCount(bool* primeList, int number){
    int count = 1;
    for(int i = 1; (2 * i + 1) * (2 * i + 1) <= number; i++){
        if(primeList[i] == true) continue;
        int n = number;
        int exponent = 0;
        while(n % (i * 2 + 1) == 0){
            exponent++;
            n /= (i * 2) + 1;
        }

        count *= (exponent + 1);
    }

    if(number % 2 == 0){
        int exponent = 0;
        while(number % 2 == 0){
            exponent++;
            number /= 2;
        }
        count *= (exponent + 1);
    }

    return count;
}

bool* primeList(int limit){
    int sieveBound = (limit - 1) / 2;
    int crossLimit = (floor(sqrt(limit)) - 1) / 2;
    bool* primes = new bool[sieveBound] { 0 };

    for(int i = 1; i <= crossLimit; i++){
        if(primes[i] == true) continue;
        for(int j = 2 * i * (i + 1); j <= sieveBound; j += (2 * i) + 1){
            primes[j] = true;
        }
    }

    return primes;
}