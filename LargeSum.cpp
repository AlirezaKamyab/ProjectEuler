// this file is written by AlirezaKamyab
// answer to problem projecteuler.net/problem=13
#include <iostream>
#include <cstdio>
using namespace std;

void getNumbers(const char* fileName, int** arr);
void add(int* A, int* B, const int n);

int main(){
    const int digits = 60;
    int** numbers = new int*[100];
    int* answer = new int[digits] {0};
    for(int i = 0; i < 100; i++) numbers[i] = new int[digits] {0};

    getNumbers("LargeSum.txt", numbers);
    for(int i = 0; i < 100; i++){
        add(answer, numbers[i], digits);
    }

    for(int i = digits - 1; i >= 0; i--) cout << answer[i];
    cout << endl;
    return 0;
}

void add(int* A, int* B, const int n){
    int extra = 0;
    for(int i = 0; i < n; i++){
        A[i] += B[i] + extra;
        extra = 0;
        
        if(A[i] > 9){
            extra = A[i] / 10;
            A[i] = A[i] % 10;
        }
    }
}

void getNumbers(const char* fileName, int** arr){
    FILE* file = fopen(fileName, "r");
    char* strNumber = new char[50];
    int counter = 0;

    while (fgets(strNumber, 8192, file))
    {
        int index = 49;
        for(int i = 0; i < 50; i++){
            arr[counter][i] = strNumber[index] - '0';
            index--;
        }

        counter++;
    }

    fclose(file);
}