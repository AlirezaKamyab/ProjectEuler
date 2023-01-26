// created in 12/5/2022 at 12:53 AM by Alireza Kamyab
#include <iostream>
using namespace std;

constexpr int MAX_SIZE = 80;
int64_t dp[MAX_SIZE][MAX_SIZE];
int64_t matrix[MAX_SIZE][MAX_SIZE];

int main() {
    for(int i = 0; i < MAX_SIZE; i++) {
        for(int j = 0; j < MAX_SIZE; j++) cin >> matrix[i][j];
    }

    for(int i = 0; i < MAX_SIZE; i++) {
        dp[0][i] = matrix[0][i] + ((i > 0)? dp[0][i - 1] : 0);
    }

    for(int j = 0; j < MAX_SIZE; j++) {
        dp[j][0] = matrix[j][0] + ((j > 0)? dp[j - 1][0] : 0);
    }

    for(int i = 1; i < MAX_SIZE; i++) {
        for(int j = 1; j < MAX_SIZE; j++) {
            int64_t fromTop = dp[i - 1][j];
            int64_t fromLeft = dp[i][j - 1];
            dp[i][j] = matrix[i][j] + min(fromTop, fromLeft);
        }
    }

    cout << dp[MAX_SIZE - 1][MAX_SIZE - 1] << endl;
    return 0;
}