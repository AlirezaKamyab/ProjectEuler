// This file is written by Alireza Kamyab
// Solution to projecteuler.net/problem=78
// Not optimized solution

#include <iostream>
using namespace std;

const int MAX_SIZE = 6e4;
int64_t dp[MAX_SIZE + 1];

int main() {
    for(int i = 0; i <= MAX_SIZE; i++) dp[i] = 1;

    for(int i = 2; i <= MAX_SIZE; i++) {
        for(int j = 0; j <= MAX_SIZE; j++) {
            if(j - i >= 0) dp[j] += dp[j - i];
            dp[j] %= int(1e6);

            if(dp[j] == 0 && i == j) {
                cout << j << endl;
                return 0;
            }
        }
    }
    return 0;
}