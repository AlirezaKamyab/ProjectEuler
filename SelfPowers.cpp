// This file is written by Alireza Kamyab 5/5/2021
// Answer to problem projecteuler.net/problem=48
#include <iostream>
using namespace std;

void sum(int* a, int* b, int n);
int* multiply(int* a, int* b, int n);
int* power(int* a, int p, int n);

int main(){
    const int n = 10;
    int* a = new int[n]{0};
    int* step = new int[n]{0};
    int* c = new int[n]{0};
    
    a[0] = 1;
    step[0] = 1;

    for(int i = 1; i <= 1000; i++){
        sum(c, power(a, i, n), n);
        sum(a, step, n);
    }

    for(int i = n - 1; i >= 0; i--) cout << c[i];
    cout << endl;
    return 0;
}

int* power(int* a, int p, int n){
    if(p == 0) {
        int* result = new int[n]{0};
        result[0] = 1;
        return result;
    }

    int* answer = power(a, p / 2, n);

    if(p % 2 == 0){
        return multiply(answer, answer, n);
    }
    else {
        return multiply(a, multiply(answer, answer, n), n);
    }
}

int* multiply(int* a, int* b, int n){
    int* result = new int[n]{0};

    for(int i = 0; i < n; i++){
        int* level = new int[n]{0};
        int extra = 0;
        for(int j = 0; j + i < n; j++){
            level[j + i] = a[j] * b[i] + extra;
            extra = 0;
            if(level[j + i] > 9){
                extra = level[j + i] / 10;
                level[j + i] = level[j + i] % 10;
            }
        }
        sum(result, level, n);
    }

    return result;
}

void sum(int* a, int* b, int n){
    int extra = 0;
    for(int i = 0; i < n; i++){
        a[i] += b[i] + extra;
        extra = 0;
        
        if(a[i] > 9){
            extra = a[i] / 10;
            a[i] = a[i] % 10;
        }
    }
}