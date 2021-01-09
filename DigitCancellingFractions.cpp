/*
 * DigitCancellingFractions.cpp
 *  Created on: Jan 7, 2021
 *      Author: Alire
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

pair<int, int> digitCancel(int numerator, int denominator);
pair<int, int> lowestCommonTerm(int numerator, int denominator);
vector<int> primeFactors(int number);

int main(int argc, char** argv) {
	pair<int, int> fraction;
	pair<int, int> canceledFraction;

	vector<pair<int, int>> answers;
	// i is denominator
	// j is numerator
	for (int i = 10; i < 100; i++) {
		for (int j = 10; j < 100; j++) {
			if (j >= i || (i % 10 == 0 && j % 10 == 0)) break;
			fraction = lowestCommonTerm(j, i);
			canceledFraction = digitCancel(j, i);
			canceledFraction = lowestCommonTerm(canceledFraction.first, canceledFraction.second);

			if (fraction.first == canceledFraction.first && fraction.second == canceledFraction.second) {
				answers.push_back(pair<int, int>{fraction.first, fraction.second});
			}
		}
	}

	int num = 1;
	int den = 1;
	for (pair<int, int> i : answers) {
		num *= i.first;
		den *= i.second;
	}

	pair<int, int> finalAnswer = lowestCommonTerm(num, den);

	cout << "the answer is " << finalAnswer.second << endl;
	return 0;
}

pair<int, int> digitCancel(int numerator, int denominator) {
	string num = to_string(numerator);
	string denom = to_string(denominator);

	for (string::iterator it = num.begin(); it != num.end(); it++) {
		string::iterator i = find(denom.begin(), denom.end(), *it);
		if (i != denom.end()) {
			num.erase(it);
			denom.erase(i);
			it = num.begin();
		}
	}
	int newNumerator = stoi(num);
	int newDenominator = stoi(denom);
	if (newNumerator != numerator || newDenominator != denominator) {
		return pair<int, int>{newNumerator, newDenominator};
	}
	return pair<int, int> {-1, -1};
}

pair<int, int> lowestCommonTerm(int numerator, int denominator) {
	vector<int> numDivisions = primeFactors(numerator);
	vector<int> denomDivisions = primeFactors(denominator);

	for (int i : numDivisions) {
		vector<int>::iterator it = find(denomDivisions.begin(), denomDivisions.end(), i);
		if (it != denomDivisions.end()) {
			numerator /= i;
			denominator /= i;
			denomDivisions.erase(it);
		}
	}

	return pair<int, int>{numerator, denominator};
}

vector<int> primeFactors(int number) {
	vector<int> temp;
	int smallestPrime = 2;
	while(number * number >= smallestPrime){
		if(number % smallestPrime == 0){
			temp.push_back(smallestPrime);
			number /= smallestPrime;
		} else {
			smallestPrime++;
		}
	}

	temp.push_back(number);

	return temp;
}
