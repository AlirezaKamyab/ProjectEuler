// This file is written by Alireza Kamyab
// Answer to the problem projecteuler.net/problem=16
#include <iostream>
#include <cmath>
using namespace std;

const int problemBase = 2;
const int problemPower = 1000;
const int MAX_INDEX = (problemPower * (log10(problemBase))) + 1;

void multiple(int* a, int* b, int* result);
void add(int* a, int* b);
int* power(int* a, int pow);

int main(){
    int summation = 0;
    int* a = new int[MAX_INDEX] {problemBase};
    int* c = power(a, problemPower);
    for(int i = 0; i < MAX_INDEX; i++) summation += c[i];
    cout << summation << endl;
    delete[] c;
    delete[] a;
    return 0;
}

void multiple(int* a, int* b, int* result){
    int k = 0;
    for(int i = 0; i < MAX_INDEX; i++){
        int* last_result = new int[MAX_INDEX] {0};
        int extra = 0;
        for(int j = 0; j < MAX_INDEX - k; j++){
            last_result[j + k] = (b[i] * a[j]) + extra;
            extra = 0;

            if(last_result[j + k] >= 10){
                extra = last_result[j + k] / 10;
                last_result[j + k] %= 10;
            }
        }
        add(result, last_result);
        k++;
        delete[] last_result;
    }
}

void add(int* a, int* b){
    int extra = 0;
    for(int i = 0; i < MAX_INDEX; i++){
        a[i] += b[i] + extra;
        extra = 0;

        if(a[i] >= 10){
           extra = a[i] / 10;
           a[i] %= 10;
        }
    }
}

int* power(int* a, int pow){
    int* res = new int[MAX_INDEX] {0};
    if(pow == 0){
        res[0] = 1;
        return res;
    }
    int* result = power(a, (int) (pow / 2));

    if(pow % 2 == 0) {
        multiple(result, result, res);
        delete[] result;
        return res;
    }
    else {
        int* temp = new int[MAX_INDEX] {0};
        multiple(result, result, temp);
        multiple(temp, a, res);
        delete[] temp;
        delete[] result;
        return res;
    }
}