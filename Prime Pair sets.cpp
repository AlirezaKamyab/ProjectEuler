#include <iostream>
#include <cmath>
using namespace std;

const int MAX_SIZE = 1E8;
bool isPrime[MAX_SIZE];

void generatePrimes();
int concat(const int&, const int&);
bool isValid(int*, const int&);

int main() {
    for(int i = 0; i < MAX_SIZE; i++) isPrime[i] = true;
    generatePrimes();

    constexpr int n = 5;
    int arr[n];

    for(int a = 3; a < 10000; a++) {
        if(a == 5) continue;
        if(!isPrime[a]) continue;
        arr[0] = a; 
        for(int b = a + 1; b < 10000; b++) {
            if(!isPrime[b]) continue;
            arr[1] = b;
            if(!isValid(arr, 2)) continue;
            for(int c = b + 1; c < 10000; c++) {
                if(!isPrime[c]) continue;
                arr[2] = c;
                if(!isValid(arr, 3)) continue;
                for(int d = c + 1; d < 10000; d++) {
                    if(!isPrime[d]) continue;
                    arr[3] = d;
                    if(!isValid(arr, 4)) continue;
                    for(int e = d + 1; e < 10000; e++) {
                        if(!isPrime[e]) continue;
                        arr[4] = e;
                        if(isValid(arr, n)) {
                            cout << a + b + c + d + e << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void generatePrimes() {
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 2; i * i <= MAX_SIZE; i++) {
        if(!isPrime[i]) continue;
        for(int j = i * i; j < MAX_SIZE; j += i) {
            isPrime[j] = false;
        }
    }
}

bool isValid(int* arr, const int& n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(!isPrime[concat(arr[i], arr[j])] || !isPrime[concat(arr[j], arr[i])]) return false;
        }
    }
    return true;
}

int concat(const int& a, const int& b) {
    int digit_b = log10(b) + 1;
    return pow(10, digit_b) * a + b;
}