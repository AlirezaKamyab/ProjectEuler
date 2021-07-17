// This file is written by Alireza Kamyab
// answer to problem projecteuler.net/problem=21
// other website https://mathschallenge.net/index.php?section=faq&ref=number/sum_of_divisors
#include <iostream>
using namespace std;

int sumOfDivisors(int n);
int sumOfProperDivisors(const int& n);

int main(){
    int sum = 0;
    for(int i = 1; i < 10000; i++){
        int b = sumOfProperDivisors(i);
        if(b > i){
            if(i == sumOfProperDivisors(b)) sum += i + b;
        }
    }

    cout << sum << endl;
    return 0;
}

int sumOfDivisors(int n) {
    int sum = 1;
    int p = 2;

    while (p * p <= n && n > 1){
        if(n % p == 0) {
            int j = p * p;
            n /= p;

            while(n % p == 0){
                j *= p;
                n /= p;
            }

            sum = sum * (j - 1);
            sum = sum / (p - 1);

        }
        if(p == 2) p = 3; else p += 2;
    }
    if(n > 1) sum *= n + 1;
    return sum;
}

int sumOfProperDivisors(const int& n){
    int sum = sumOfDivisors(n) - n;
    return sum;
}