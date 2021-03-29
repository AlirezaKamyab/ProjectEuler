// This file is written by Alireza Kamyab 3/29/2021
// Question is projecteuler.com/problem=40
#include <iostream>
#include <cmath>
using namespace std;

/// <summary>
/// This function returns a digit in the number with specific index like arrays but from right to left
/// </summary>
int digit(int number, int index);

int main() {
	int digits = 0;
	int selected = 1;
	int multiplier = 1;
	for (int i = 1;; i++) {
		int iDigit = static_cast<int>(log10(i)) + 1;
		digits += iDigit;

		if (digits >= selected && digits - selected <= iDigit - 1) {
			multiplier *= digit(i, digits - selected);
			selected *= 10;
		}

		if (selected > 1000000) break;
	}

	cout << multiplier << endl;
	return 0;
}

int digit(int number, int index) {
	int result = number % 10;
	for (int i = 0; i < index; i++) {
		number /= 10;
		result = number % 10;
	}
	return result;
}