//Created on: Dec 17, 2020 by Alireza
#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int number);
int Prime(int index);

int main(int argc, char ** argv){
	int limit = 20;
	long long unsigned int answer = 1;
	for(int i = 0; i <= limit; ++i){
		int power = 0;
		int prime = Prime(i);
		if(prime <= limit){
			power = floor((log(limit)) / (log(prime)));
			answer *= (int)(pow(prime, power));
		}
	}
	cout << "The answer is " << answer << endl;
	return 0;
}

bool isPrime(int number){
	if(number <= 1) return false;
	for(int i = 2; i < ((int)(sqrt(number))) + 1; ++i){
		if(number % i == 0) return false;
	}
	return true;
}

int Prime(int index){
	int counter = 0;
	int number = 2;
	while(true){
		if(isPrime(number)){
			if(counter == index){
				return number;
			}
			else{
				counter++;
			}
		}
		number++;
	}
}
