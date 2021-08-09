// This file is written by Alireza Kamyab
// Answer to projecteuler.net/problem=52

#include <iostream>
using namespace std;

constexpr int MAX_LENGTH = 8;

bool search(const int* arr, const int& n, const int& number);
bool isValid(const int* arr, const int& n, const int m);
void add(int* arr, int& n, const int value = 1);
void print(const int* arr, const int& n);

int main() {
    int n = 1;
    int arr[MAX_LENGTH] {1,0,0,0,0,0,0,0};

    while(true) {
        if(isValid(arr, n, 2) && isValid(arr, n, 3) && isValid(arr, n, 4) && isValid(arr, n, 5) && isValid(arr, n, 6)) {
            print(arr, n);
            break;
        }

        add(arr, n);
    }

    return 0;
}

bool isValid(const int* arr, const int& n, const int m) {
    int temp[MAX_LENGTH];

    int extra = 0;
    for(int i = 0; i < n; i++) {
        int a = (m * arr[i]) + extra;
        temp[i] = a % 10;
        extra = a / 10;
        if(!search(arr, n, temp[i])) return false;
    }

    if(extra > 0) return false;

    return true;
}

bool search(const int* arr, const int& n, const int& number) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == number) return true;
    }
    return false;
}

void add(int* arr, int& n, const int value) {
    int extra = 0;
    arr[0] += value;
    extra = arr[0] / 10;
    arr[0] %= 10;
    for(int i = 1; i < n; i++) {
        arr[i] += extra;
        extra = arr[i] / 10;
        arr[i] %= 10;
    }

    if(extra > 0) arr[n++] += extra;
}

void print(const int* arr, const int& n) {
    for(int i = n - 1; i >= 0; i--) cout << arr[i];
    cout << endl;
}