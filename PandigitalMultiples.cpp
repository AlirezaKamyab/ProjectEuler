// This file is written by Alireza Kamyab 3/28/2021
// What is the largest 1 to 9 pandigital 9 - digit number that can be formed as the concatenated product of an 
// integer with(1, 2, ..., n) where n > 1 ?
#include <iostream>
#include <cmath>
#include <cinttypes>
using namespace std;

uint64_t concat(int number);
bool isPandigital(uint64_t number);

int main() {
	int max = 0;
	for (int i = 1; i < 10000; i++) {
		uint64_t concatenated = concat(i);
		if (isPandigital(concatenated) && concatenated > max) {
			max = concatenated;
		}
	}
	cout << max << endl;
	return 0;
}

bool isPandigital(uint64_t number) {
	// For finding whether the number is pandigital or not, I checked whether it is 9 digit first
	// Given that every 9-digit number which its digit product is 9! and digit sum is 45 must constitude with number 1 to 9
	// in its digits
	// This function runs in time complexity of log(number)
	int digits = log10(number) + 1;
	if (digits != 9) return false;

	int multiplication = 1;
	int summation = 0;
	while (number >= 1) {
		int remainder = number % 10;
		multiplication *= remainder;
		summation += remainder;
		number /= 10;
	}

	if (multiplication == 362880 && summation == 45) return true;
	else return false;
}

uint64_t concat(int number) {
	// Using (int)log10 + 1 of a number return the exact digits of that number
	// This is a good solution for finding the digits rather than using O(n) running time for checking every digit. 
	// Time complexity of log10 function for integers are supposedly O(log n)
	// and using pow function which its complexity is O(log n) makes it efficient
	uint64_t concatenated = number;
	int counter = 2;
	while (log10(concatenated) + 1 <= 9) {
		int multiplication = number * counter;
		int multiplicationDigits = log10(multiplication) + 1;
		concatenated *= pow(10, multiplicationDigits);
		concatenated += multiplication;
		counter++;
	}
	return concatenated;
}