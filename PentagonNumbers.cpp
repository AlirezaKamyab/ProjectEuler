// This file is written by Alireza Kamyab
// Answer to the problem projecteuler.net/problem=44
#include <iostream>
#include <cmath>
#include <cinttypes>
using namespace std;

uint64_t getPentagon(int n);
bool isPentagon(int number);

int main() {
	uint64_t minDifference = 0;
	for (int i = 1;; i++) {
		uint64_t difference = 0;
		uint64_t a = getPentagon(i);
		for (int j = i + 1; j < 10000; j++) {
			if (difference > minDifference && minDifference != 0) break;
			uint64_t b = getPentagon(j);
			difference = b - a;
			if (isPentagon(a + b) && isPentagon(difference)) {
				if (minDifference > difference || minDifference == 0) {
					minDifference = difference;
					cout << minDifference << endl;
				}
			}
		}
	}
	return 0;
}

uint64_t getPentagon(int n) {
	// Formula: n(3n-1) / 2
	return (n * (3 * n - 1)) / 2;
}

bool isPentagon(int number) {
	// If number = p
	// Formula: 3n^2 - n - 2p = 0
	float delta = 1 + (24 * number);
	float positiveRoot = (1 + sqrt(delta)) / 6;
	if (positiveRoot != floor(positiveRoot)) return false;
	return true;
}