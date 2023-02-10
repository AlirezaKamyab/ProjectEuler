#include <iostream>
using namespace std;

constexpr int MAX_SIZE = 1e8;
int64_t memo[MAX_SIZE];
int64_t sum_square_digit(const int&);
int64_t func(const int&);

int main() {
    int cnt = 0;
    for(int i = 1; i < 10000000; i++) {
        if(func(i) == 89) cnt++;
    }
    cout << cnt << endl;
    return 0;
}

int64_t sum_square_digit(const int& n) {
    int64_t sum = 0;
    int number = n;
    while(number != 0) {
        int r = number % 10;
        sum += r * r;
        number /= 10;
    }

    return sum;
}

int64_t func(const int& n) {
    if(n == 1) return 1;
    if(n == 89) return 89;

    if(memo[n] != 0) return memo[n];
    int64_t ssd = sum_square_digit(n);
    memo[n] = func(ssd);
    return memo[n];
}