// This file is written by AlirezaKamyab 5/7/2021
// Answer to problem projecteuler.net/problem=50
#include <iostream>
using namespace std;

bool isPrime(int number);
int nextPrime(int number);
void generatePrimeConsecutive(int initiate, int limit, int& maxStage, int& longestConsecutive);
void findLongestConsecutivePrime(int limit, int& count, int& longestConsecutive);

int main(){
    int count = 0;
    int longestConsecutive = 0;
    findLongestConsecutivePrime(1000000, count, longestConsecutive);
    cout << "Max stage is " << count << " Longest consecutive is " << longestConsecutive << endl;
    return 0;
}

void findLongestConsecutivePrime(int limit, int& count, int& longestConsecutive){
    int counter = 2;
    while (counter < limit){
        generatePrimeConsecutive(counter, limit, count, longestConsecutive);
        counter = nextPrime(counter);
    }
}

void generatePrimeConsecutive(int initiate, int limit, int& maxStage, int& longestConsecutive){
    int stage = 1;
    int counter = initiate;
    int sum = counter;

    while (sum <= limit){
        counter = nextPrime(counter);
        sum += counter;
        stage++;

        if (sum > limit) return;
        if (stage > maxStage && isPrime(sum)){
            maxStage = stage;
            longestConsecutive = sum;
        }
    }
}

int nextPrime(int number){
    for(int i = number + 1; true; i++){
        if (isPrime(i)) return i;
    }

    return 0; // Never is going to be called
}

bool isPrime(int number){
    if (number <= 1) return false;
    if (number < 4) return true;
    if (number % 2 == 0) return false;
    if (number < 9) return true;
    if (number % 3 == 0) return false;

    int counter = 1;
    int limit = 0;

    while (limit * limit <= number){
        limit = counter * 6;
        if (number % (limit + 1) == 0) return false;
        if (number % (limit - 1) == 0) return false;
        counter++;
    }

    return true;
}