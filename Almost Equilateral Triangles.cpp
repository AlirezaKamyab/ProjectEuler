#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int64_t p = 0;
    for(int64_t a = 5; 3 * a + 1 <= 1e9; a++) {
        int64_t b = a + 1;
        if(b % 2 != 0) continue;
        long double h = (long double)(a * a) - (long double)(b * b) / 4;
        
        int64_t approxH = sqrt(h);
        if(approxH * approxH != h) continue;
        p += 3 * a + 1;
    }

    for(int64_t a = 5; 3 * a - 1 <= 1e9; a++) {
        int64_t b = a - 1;
        if(b % 2 != 0) continue;
        long double h = (long double)(a * a) - (long double)(b * b) / 4;
        
        int64_t approxH = sqrt(h);
        if(approxH * approxH != h) continue;
        p += 3 * a - 1;
    }

    cout << p << endl;
    return 0;
}
