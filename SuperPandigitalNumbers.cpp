// This file is created by Alireza Kamyab
/*A positive number is pandigital in base b if it contains all digits from 0 to b - 1 at least once
when written in base b.
A n-super-pandigital number is a number that is simultaneously pandigital in all bases from 2 to n inclusively.
For example 978 = 11110100102 = 11000203 = 331024 = 124035 is the smallest 5-super-pandigital number.
Similarly, 1093265784 is the smallest 10-super-pandigital number.
The sum of the 10 smallest 10-super-pandigital numbers is 20319792309.
What is the sum of the 10 smallest 12-super-pandigital numbers?*/
// This solution is not AT ALL optimized. If you know a better way, alirezakamyab19@gmail.com
#include <iostream>
#include <cmath>
#include <cinttypes>
#include <vector>
#include <algorithm>
using namespace std;

/// <summary>
/// Converts a 10-based number to given base
/// </summary>
/// <param name="number">A positive integer</param>
/// <param name="base">A base</param>
/// <returns>A pair of int-array for digits and number of digits</returns>
bool isPandigital(uint64_t number, int base);

/// <summary>
/// Takes a vector of digist and tells whether it is pandigital
/// </summary>
/// <param name="vec">vector of digits</param>
/// <param name="vecBase">base of the vector of digits</param>
/// <param name="maxBase">max-base</param>
/// <returns>returns whether it is pandigital or not as a boolean</returns>
bool isNPandigital(vector<int>& vec, int vecBase, int maxBase);

/// <summary>
/// Making a n-based number to ten based
/// </summary>
/// <param name="digits">vector of digits for the number to convert</param>
/// <param name="base">base of the number</param>
/// <returns>an integer base-10</returns>
uint64_t vectorToNumber(vector<int>& digits, int base);


int main() {
	vector<int> vec = { 1,0,2,3,4,5,6,7,8,9,10,11 };
	int basedVec = 12;
	int max_base = basedVec - 1;

	uint64_t summation = 0;
	int counter = 0;
	do {
		if (vec[0] == 0) continue;
		if (counter == 10) break;

		if (isNPandigital(vec, basedVec, max_base)) {
			cout << counter << " is counted" << endl;
			counter++;
			summation += vectorToNumber(vec, basedVec);
		}
	} while (next_permutation(vec.begin(), vec.end()));
	cout << "Summation is " << summation << endl;


	return 0;
}

bool isNPandigital(vector<int>& vec, int vecBase, int maxBase) {
	uint64_t number = vectorToNumber(vec, vecBase);
	if (maxBase == 2) return true;
	if (isPandigital(number, maxBase) == false) return false;

	return isNPandigital(vec, vecBase, maxBase - 1);
}

bool isPandigital(uint64_t number, int base) {
	vector<int> digits;
	for (int i = 0; i < base; i++) digits.push_back(0);

	while (number >= 1) {
		digits[number % base]++;
		number /= base;
	}

	for (int i = 0; i <= base - 1; i++) {
		if (digits[i] == 0) return false;
	}
	return true;
}

uint64_t vectorToNumber(vector<int>& digits, int base) {
	uint64_t result = 0;
	uint64_t multiplier = 1;
	for (int i = digits.size() - 1; i >= 0; i--) {
		result += multiplier * digits[i];
		multiplier *= base;
	}
	return result;
}