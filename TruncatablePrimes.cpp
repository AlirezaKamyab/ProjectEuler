// This file is written by Alireza Kamyab 3/25/2021
// The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits 
// from left to right, and remain prime at each stage: 3797, 797, 97, and 7. 
// Similarly we can work from right to left: 3797, 379, 37, and 3.
// Find the sum of the only eleven primes that are both truncatable from left to rightand right to left.
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int number);
bool isTruncatableFromRight(int number);
bool isTruncatableFromLeft(int number);

int main() {
	int summation = 0;
	int counter = 0;
	int number = 10;
	while (counter < 11) {
		if (isTruncatableFromLeft(number) && isTruncatableFromRight(number)) {
			summation += number;
			counter++;
		}
		number++;
	}
	cout << summation << endl;
	return 0;
}

bool isTruncatableFromRight(int number) {
	while (number >= 1) {
		if (isPrime(number) == false) return false;
		number /= 10;
	}
	return true;
}

bool isTruncatableFromLeft(int number) {
	if (number <= 9) return isPrime(number);

	int multiply = 1;
	int result = 0;
	while (number > 9) {
		result += (number % 10) * multiply;
		multiply *= 10;
		number /= 10;
	}
	if (isPrime(result) == false) return false;
	return isTruncatableFromLeft(result);
}

bool isPrime(int number) {
	if (number <= 1) return false;
	if (number < 4) return true;
	if (number % 2 == 0) return false;
	if (number < 9) return true;
	if (number % 3 == 0) return false;

	int counter = 1;
	int limit = 0;
	while (limit <= floor(sqrt(number))) {
		limit = counter * 6;
		if (number % (limit - 1) == 0) return false;
		if (number % (limit + 1) == 0) return false;
		counter++;
	}

	return true;
}