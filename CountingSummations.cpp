// This file is written by Alireza Kamyab
// Solution to problem projecteuler.net/problem=76
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int64_t dp[MAX_SIZE + 1];

int main() {
    for(int i = 0; i <= MAX_SIZE; i++) dp[i] = 1;

    for(int i = 2; i < MAX_SIZE; i++) {
        for(int j = 0; j <= MAX_SIZE; j++) {
            if(j - i >= 0) dp[j] += dp[j - i];
        }
    }

    cout << "Result is " << dp[MAX_SIZE] << endl;
    return 0;
}