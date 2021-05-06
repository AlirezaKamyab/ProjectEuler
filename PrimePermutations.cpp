// This file is written by Alireza Kamyab 5/6/2021
// Answer to problem projecteuler.net/problem=49
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int number);
bool isPermutation(int a, int b);
int search(int* arr, const int n, int value);

int main(){
    const int limit = 10000;
    const int begin = 1488;

    for(int i = begin; i < limit; i++){
        if(!isPrime(i)) continue;

        for(int diff = 2; i + diff + diff < limit; diff += 2){
            int j = i + diff;
            if(!isPrime(j) || !isPermutation(i, j)) continue;

            int k = j + diff;
            if(isPrime(k) && isPermutation(k, j)){
                printf("%d%d%d\n", i, j, k);
                return 0;
            }
        }
    }
    return 0;
}

bool isPermutation(int a, int b){
    int aIndex = (int)log10(a) + 1; 
    int bIndex = (int)log10(b) + 1; 
    int* arrA = new int[aIndex];
    int* arrB = new int[bIndex];

    for(int i = 0; i < aIndex; i++){
        arrA[i] = a % 10;
        a /= 10;
    }

    for(int i = 0; i < bIndex; i++){
        arrB[i] = b % 10;
        b /= 10;
    }

    if(aIndex != bIndex) return false;

    for(int i = 0; i < aIndex; i++){
        int index = search(arrB, bIndex, arrA[i]);
        
        if(index == -1) return false;
        else arrB[index] = -1;
    }

    return true;
}

int search(int* arr, int n, int value){
    for(int i = 0; i < n; i++){
        if(arr[i] == value) return i;
    }

    return -1;
}

bool isPrime(int number){
    if(number <= 1) return false;
    if(number < 4) return true;
    if(number % 2 == 0) return false;
    if(number < 9) return true;
    if(number % 3 == 0) return false;

    int counter = 1;
    int limit = 0;
    while(limit * limit <= number){
        limit = counter * 6;
        if(number % (limit + 1) == 0) return false;
        if(number % (limit - 1) == 0) return false;
        counter++;
    }

    return true;
}