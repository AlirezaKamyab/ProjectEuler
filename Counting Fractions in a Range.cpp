#include <iostream>
using namespace std;

int gcd(const int& a, const int& b);
constexpr int LIMIT = 12000;
int arr[LIMIT + 1][LIMIT + 1];

int main() {
    int cnt = 0;
    for(int d = 1; d <= LIMIT; d++) {
        for(int n = 1; n < d; n++) {
            if(gcd(n, d) != 1) continue;
            double frac = (double) n / d;
            if(frac > (1.0 / 3) && frac < (1.0 / 2)) cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}

int gcd(const int& a, const int& b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}