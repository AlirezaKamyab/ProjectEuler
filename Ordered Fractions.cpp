#include <iostream>
using namespace std;

int gcd(const int& a, const int& b);

int main() {
    for(int y = 1e6; y > 0; y--) {
        if((3 * y - 1) % 7 != 0) continue;
        int x = (3 * y - 1) / 7;
        if(gcd(x, y) == 1) {
            cout << x << endl;
            return 0;
        }
    }
    return 0;
}

int gcd(const int& a, const int& b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}