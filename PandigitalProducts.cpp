//Created on: Jan 1, 2021 by Alireza
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int digits(int number);
bool isPandigital(int a, int b);
int isExisted(vector<int> vec, int number);

int main() {
	int summation = 0;
	vector<int> products;
	for (int i = 1;; i++) {
		if (digits(i) > 3) break; // If I is 4 digit so j = i + 1 and the product will have more than 9
		for (int j = i + 1;; j++) {
			if (digits(j) + digits(i) > 5) break; // If digits of i and j exceeds 5, the product will be more than 9 digits
			int product = i * j;
			if (isPandigital(i, j) && !isExisted(products, product)) {
				summation += product;
				products.push_back(product);
			}
		}
	}

	cout << summation << endl;
	return 0;
}

bool isPandigital(int a, int b) {
	int* numbers = new int[] { 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int product = a * b;

	int a_digits = digits(a);
	int b_digits = digits(b);
	int c_digits = digits(product);
	if (a_digits + b_digits + c_digits != 9) return false;

	while (a != 0) {
		numbers[(a % 10) - 1]++;
		a /= 10;
	}

	while (b != 0) {
		numbers[(b % 10) - 1]++;
		b /= 10;
	}

	while (product != 0) {
		numbers[(product % 10) - 1]++;
		product /= 10;
	}

	for (int i = 0; i < 9; i++) {
		if (numbers[i] == 0) return false;
		if (numbers[i] > 1) return false;
	}
	return true;
}

int digits(int number) {
	return int(log10(number)) + 1;
}

int isExisted(vector<int> vec, int number) {
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		if (*it == number) return true;
	}
	return false;
}