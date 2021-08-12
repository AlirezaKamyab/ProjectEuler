// This file is written by Alireza Kamyab
// Answer to projecteuler.net/problem=53
#include <iostream>
using namespace std;

constexpr int MAX_N = 100;
constexpr int LIMIT = 1000000;

int main() {
    int count = 0;
    int C[MAX_N + 1] {1,1};
    for(int n = 2; n <= MAX_N; n++) {
        C[n - 1] = 1;
        for(int r = n - 1; r >= 1; r--) {
            C[r] = C[r - 1] + C[r];
            if(C[r] > LIMIT) {
                count += r - (n - r) + 1;
                break;
            }
        }
    }

    cout << count << endl;
    return 0;
}