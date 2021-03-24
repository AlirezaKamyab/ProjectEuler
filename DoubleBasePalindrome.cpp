// this file is written by Alireza Kamayb 3/25/2021
// The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.
// Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
#include <iostream>
#include <math.h>
using namespace std;

pair<int*, int> basedTen(int number);
pair<int*, int> toBaseTwo(int number);
bool isPalindrome(int* A, int p, int r);

int main() {
	int summation = 0;
	for (int i = 1; i < 1000000; i++) {
		pair<int*, int> ten = basedTen(i); // making ten base into the array
		pair<int*, int> two = toBaseTwo(i); // calculating a base ten into based to and convert to array

		// checking whether both numbers are palindromic numbers on both bases
		if (isPalindrome(ten.first, 0, ten.second - 1) && isPalindrome(two.first, 0, two.second - 1)) {
			summation += i;
		}
	}

	cout << summation << endl;
	return 0;
}

bool isPalindrome(int* A, int p, int r) {
	if (p == r) return true;
	if (r - p == 1) return A[p] == A[r];
	if (A[p] != A[r]) return false;

	return isPalindrome(A, p + 1, r - 1);
}

pair<int*, int> basedTen(int number) {
	int indexes = floor(log10(number)) + 1;
	int* digits = new int[indexes];

	for (int i = 0; i < indexes; i++) {
		digits[i] = number % 10;
		number /= 10;
	}

	return { digits, indexes };
}

pair<int*, int> toBaseTwo(int number) {
	int indexes = floor(log(number) / log(2)) + 1;
	int* digits = new int[indexes];

	for (int i = 0; i < indexes; i++) {
		digits[i] = number % 2;
		number /= 2;
	}

	return { digits, indexes };
}