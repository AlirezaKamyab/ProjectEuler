// This file is written by Alireza Kamyab 3/29/2021
// Question is projecteuler.net/problem=41
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/// <summary>
/// takes a vector and converts it to a number
/// </summary>
int convertToNumber(vector<int>& vec);

/// <summary>
/// Takes a number and tells whether it is prime or not
/// </summary>
bool isPrime(int number);

int main() {
	/// <summary>
	/// pandigital of 1 and 2 and 3 and 5 and 6 and 8 and 9 are not prime since
	/// they are multiples of 3
	/// So 4 and 7-digits are left to be prime
	/// </summary>
	vector<int> numbers = { 1,2,3,4,5,6,7 };
	int max = 0;
	do {
		int convertedNumber = convertToNumber(numbers);
		if (isPrime(convertedNumber) && convertedNumber > max) {
			max = convertedNumber;
		}
	} while (next_permutation(numbers.begin(), numbers.end()));

	cout << max << endl;
	return 0;
}

int convertToNumber(vector<int>& vec) {
	int number = 0;
	for (int i : vec) {
		number *= 10;
		number += i;
	}
	return number;
}

bool isPrime(int number) {
	if (number == 1) return false;
	if (number < 4) return true;
	if (number % 2 == 0) return false;
	if (number < 9) return true;
	if (number % 3 == 0) return false;

	int counter = 1;
	int limit = 0;
	while (limit <= sqrt(number)) {
		limit = counter * 6;
		if (number % (limit - 1) == 0) return false;
		if (number % (limit + 1) == 0) return false;
		counter++;
	}
	return true;
}