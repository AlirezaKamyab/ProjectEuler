//Created on: Dec 13, 2020 by Alireza
#include<iostream>
using namespace std;

int Quadratic(int, int, int);
bool isPrime(int);

int main(int argc, char ** argv){
	int maxPrimes = 0;
	int maxi = 0, maxj = 0;
	int numberPrimes = 0;
	int counter = 0;

	for(int i = -1000; i < 1000; i++){
		for(int j = -1000; j <= 1000; j++){
			numberPrimes = 0;
			counter = 0;
			while (true){
				int result = Quadratic(i, j, counter);
				if(isPrime(result)){
					numberPrimes++;
				}else{
					if(maxPrimes < numberPrimes){
						maxPrimes = numberPrimes;
						maxi = i;
						maxj = j;
					}
					break;
				}
				counter++;
			}
		}
	}
	cout << "The answer is " << maxi * maxj << endl;
	return 0;
}

int Quadratic(int a, int b, int n){
	return (n * n) + (a * n) + (b);
}

bool isPrime(int number){
	if(number <= 1) return false;
	for(int i = 2; i < number; i++){
		if(number % i == 0) return false;
	}
	return true;
}
