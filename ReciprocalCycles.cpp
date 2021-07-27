// This file is written by Alireza Kamyab
// Answer to projecteuler.net/problem=26
#include <iostream>
using namespace std;

/* Let us calculate 1/7, the answer is 0.1428571....we can simply multiply 1/7 by 10 and get 10/7 which is 1.428571..., we can reproduce the decimal number and 
remove the integer number by subtracting what makes the integer number in 1.428571..., which (10 - 7)/7 or for convenience we can write (10%7) / 7 
which is 3/7 = 0.428571...
again we do the same thing for 0.428571..., we have to multiply it by 10
which is 30/7 and will be 4.28571..., decimal part of the number is (30%7)/7 which is 2/7
So 2/7 = 0.28571...
And for the rest
	6/7 = 0.8571...
	4/7 = 0.571...
	5/7 = 0.71...
Let's continue this one more time, so we multiply this by 10 and get 50/7, since we only need the 
decimal number we find the mod(50, 7) which is 1
So we have to calculate 1/7, which gets us where we started
Length of the decimals that repeats, which took us 6 divisions to get to the starting point is 6


This is a function that returns the length of the repeating decimals

Length(a, b): #for division a/b
    startPoint = a
    counter = 0

    a = (a*10) % b
    counter = counter + 1 #because we just did one of the divisions above

    while(a != startPoint):
        a = (a*10) % b
        counter = counter + 1
    
    return counter */

int Length(int a, int b);
bool isPrime(int number);

int main(){
    int maxLength = 0;
    int maxDenominator = 0;
    for(int i = 1; i < 1000; i++){
        if(!isPrime(i)) continue;

        int decimalLength = Length(1, i);
        if(decimalLength > maxLength){
            maxLength = decimalLength;
            maxDenominator = i;
        }
    }

    cout << maxDenominator << endl;
    return 0;
}

int Length(int a, int b){
    int startingPoint = a;
    int counter = 0;

    a = (a * 10) % b;
    counter = counter + 1;

    while(a != startingPoint && a != 0){
        a = (a * 10) % b;
        counter = counter + 1;
    }

    return counter;
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