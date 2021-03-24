// This file is written by Alireza Kamyab in 3/24/2021
// todo: Find all cicular primes less than one million

#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n);
int shift(int n);
int digits(int n);
bool isCircular(int n);

int main() {
	int counter = 1;
	for (int i = 3; i < 1000000; i += 2) {
		if (isPrime(i) && isCircular(i)) {
			counter++;
		}
	}

	cout << counter << endl;

	return 0;
}

bool isCircular(int n) {
	int shifted = shift(n);
	int digit = digits(n);
	for(int i = 0; i < digit - 1; i++) {
		if (isPrime(shifted) == false) return false;

		// if a number has zero in it, it should not be a prime number and makes the shifting one or more less digit
		if (digits(shifted) < digit) return false;
		shifted = shift(shifted);
	}
	return true;
}

int shift(int n) {
	int result = 0;
	int multiply = 1;
	while (n > 9) {
		multiply *= 10;
		result += (n % 10) * multiply;
		n /= 10;
	}
	return result + n;
}

int digits(int n) {
	int counter = 0;
	while (n >= 1) {
		n /= 10;
		counter++;
	}
	return counter;
}

bool isPrime(int n) {
	if (n <= 1) return false; // Numbers less than or equal to one are not prime
	if (n < 4) return true; // 2 and 3 are prime given less than one eliminated
	if (n % 2 == 0) return false; // even numbers not including 2 are not prime
	if (n < 9) return true; // given 4, 6 and 8 eliminated every number less than 9 are prime
	if (n % 3 == 0) return false;

	// every prime greater than 3 could be written as 6k +/- 1
	// for every number n, there could only be one or none primes more than sqrt(n)
	// if a number, n, is defined, for every p less than sqrt(n) there is q such that n / p = q

	int counter = 1;
	int limit = 0;
	while (limit <= floor(sqrt(n))) {
		limit = counter * 6;
		if (n % (limit + 1) == 0) return false;
		if (n % (limit - 1) == 0) return false;
		counter++;
	}
	return true;
}