// This file is written by Alireza Kamyab 3/30/2021
// Solution to problem projecteuler.net/problem=43
#include <iostream>
#include <vector>
#include <algorithm>
#include <cinttypes>
using namespace std;

bool hasProperty(vector<int> arr);
int primeAfter(int number);
uint64_t convertVectorToNumber(vector<int> numbers);

int main() {
	vector<int> numbers = { 1,0,2,3,4,5,6,7,8,9 };
	uint64_t summation = 0;
	do {
		if (hasProperty(numbers)) summation += convertVectorToNumber(numbers);
	} while (next_permutation(numbers.begin(), numbers.end()));

	cout << summation << endl;

	return 0;
}

uint64_t convertVectorToNumber(vector<int> numbers) {
	uint64_t result = 0;
	for (int i = 0; i < numbers.size(); ++i) {
		result *= 10;
		result += numbers[i];
	}
	return result;
}

bool hasProperty(vector<int> arr) {
	int prime = 2;
	for (int i = 1; i <= 7; i++) {
		int number = 0;
		number += arr[i];
		number *= 10;

		number += arr[i + 1];
		number *= 10;

		number += arr[i + 2];

		if (number % prime != 0) return false;
		prime = primeAfter(prime);
	}
	return true;
}

int primeAfter(int number) {
	if (number == 2) return 3;
	if (number == 3) return 5;
	int remainder = number % 6;
	int counter = number / 6;
	if (remainder > 1) {
		return (counter + 1) * 6 + 1;
	}
	else {
		return (counter + 1) * 6 - 1;
	}
}