#include <iostream>
using namespace std;

constexpr int MAX_SIZE = 80;
int arr[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];

int main() {
    for(int i = 0; i < MAX_SIZE; i++) {
        for(int j = 0; j < MAX_SIZE; j++) cin >> arr[i][j];
    }

    // Initialization
    for(int i = 0; i < MAX_SIZE; i++) dp[i][MAX_SIZE - 1] = arr[i][MAX_SIZE - 1];

    for(int j = MAX_SIZE - 1; j >= 0; j--) {
        dp[0][j] = dp[0][j + 1] + arr[0][j];
        for(int i = 1; i < MAX_SIZE; i++) {
            dp[i][j] = min(dp[i - 1][j] + arr[i][j], dp[i][j + 1] + arr[i][j]);
        }

        dp[MAX_SIZE - 1][j] = min(dp[MAX_SIZE - 1][j], dp[MAX_SIZE - 1][j + 1] + arr[MAX_SIZE - 1][j]);
        for(int i = MAX_SIZE - 2; i >= 0; i--) {
            dp[i][j] = min(dp[i][j], dp[i + 1][j] + arr[i][j]);
        }
    }

    int minimum = 1000000;
    for(int i = 0; i < MAX_SIZE; i++) {
        if(dp[i][0] < minimum) minimum = dp[i][0];
    }

    cout << minimum << endl;
    return 0;
}