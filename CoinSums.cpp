// Created on: Dec 27, 2020 by Alireza
#include<iostream>
using namespace std;

int CoinSums(int number);

int main(int argc, char **argv) {

	cout << CoinSums(200) << endl;
	return 0;
}

int CoinSums(int number) {
	int ways = 0;
	int a = 1, b = 2, c = 5, d = 10, e = 20, f = 50, g = 100, h = 200;
	for (int hCounter = 0; hCounter <= number / h; hCounter++) {
		for (int j = 0; j <= number / g; j++) {
			for (int fCounter = 0; fCounter <= number / f; fCounter++) {
				for (int eCounter = 0; eCounter <= number / e; eCounter++) {
					for (int dCounter = 0; dCounter <= number / d; dCounter++) {
						for (int cCounter = 0; cCounter <= number / c;
								cCounter++) {
							for (int bCounter = 0; bCounter <= number / b;
									bCounter++) {
								for (int aCounter = 0; aCounter <= number / a;
										aCounter++) {
									if (hCounter * h + j * g + fCounter * f
											+ eCounter * e + dCounter * d
											+ cCounter * c + bCounter * b
											+ aCounter * a > number)
										break;
									if (hCounter * h + j * g + fCounter * f
											+ eCounter * e + dCounter * d
											+ cCounter * c + bCounter * b
											+ aCounter * a == number)
										ways++;
									else
										continue;
								}
							}
						}
					}
				}
			}
		}
	}
	return ways;
}
