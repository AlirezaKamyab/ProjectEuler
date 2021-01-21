/*
 * DigitFactorials.cpp
 *
 *  Created on: Jan 21, 2021
 *      Author: Alire
 */
#include<iostream>
#include<map>
using namespace std;

int Factorial(int number);
int digitFactorial(int number);

int main(int argc, char ** argv){
	/* Why max value to be searched is 99999
	 * Every number over 8-digit, even if all its digits are 9, all (8 * 9!) cannot be 8-digits
	 * 7-digit numbers are left with starting of 2 nines as digits and 4 eights and the rest 0 to be 7 at start
	 * 	leaving 7-digits as they cannot make any number as DigitFactorial
	 * 6-digit numbers need only one 9 to make the 6-digit number, while using 3 eights could be adequate
	 * 		having it 2 eights and exactly 4 sevens will be the minimum, only these numbers could be calculated and
	 * 		leave all 6-digits, just like 7-digits */
	int summation = 0;
	for(int i = 3; i <= 99999; i++){
		if(i == digitFactorial(i)){
			summation += i;
		}
	}

	cout << "the answer is " << summation << endl;
	return 0;
}

int digitFactorial(int number){
	int summation = 0;
	while(number > 0){
		summation += Factorial(number % 10);
		number /= 10;
	}

	return summation;
}

map<int, int> memo;
int Factorial(int number){
	if (number == 0) return 1;

	map<int, int>::iterator it = memo.find(number);
	if(it != memo.end()) return it->second;

	int result = number * Factorial(number - 1);
	memo[number] = result;
	return result;
}



