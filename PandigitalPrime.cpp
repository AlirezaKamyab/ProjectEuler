// This file is written by Alireza Kamyab 3/29/2021
// Question is projecteuler.net/problem=41
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/// <summary>
/// takes a vector and converts it to a number
/// </summary>
int convertToNumber(vector<int>& vec);

/// <summary>
/// Takes a number and tells whether it is prime or not
/// </summary>
bool isPrime(int number);

/// <summary>
/// Takes an array of integers with size of p and takes a vector of vector of integers
/// and adds permutations to that
/// </summary>
void permutations(vector<int> arr, int p, int r, vector<vector<int>>& result);

int main() {
	/// <summary>
	/// pandigital of 1 and 2 and 3 and 5 and 6 and 8 and 9 are not prime since
	/// they are multiples of 3
	/// So 4 and 7-digits are left to be prime
	/// </summary>
	vector<int> numbers = { 1,2,3,4,5,6,7 };
	vector<vector<int>> allPermutaion;
	permutations(numbers, 0, numbers.size() - 1, allPermutaion);

	int max = 0;
	int counter = 0;
	for (vector<int> i : allPermutaion) {
		int convertedNumber = convertToNumber(i);
		if (isPrime(convertedNumber) && convertedNumber > max) {
			max = convertedNumber;
		}
	}
	cout << max << endl;
	return 0;
}

void permutations(vector<int> arr, int p, int r, vector<vector<int>>& result) {
	if (p == r) {
		result.push_back(arr);
	}
	
	for (int i = p; i <= r; i++) {
		int temp = arr[p];
		arr[p] = arr[i];
		arr[i] = temp;

		permutations(arr, p + 1, r, result);

		temp = arr[p];
		arr[p] = arr[i];
		arr[i] = temp;
	}
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