/*
 * ThousandDigitFibonacciNumber.cpp
 *
 *  Created on: Jan 19, 2021
 *      Author: Alire
 */
#include <iostream>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;

typedef vector<unsigned int> Digit;

Digit add(Digit  a, Digit b);
Digit fibo(int index);

int main(int argc, char ** argv){
	Digit answer;
	int counter = 1;
	while(answer.size() != 1000){
		answer = fibo(counter);
		counter++;
	}

	cout << "the answer is " << counter << endl;
	return 0;
}

Digit fibo(int index){
	static map<int, Digit> memo;

	if(index == 0 || index == 1){
		Digit temp;
		temp.push_back(1);
		return temp;
	}
	if(index < 0) {
		Digit temp;
		temp.push_back(0);
		return temp;
	}

	map<int, Digit>::iterator it = memo.find(index);
	if(it != memo.end()) return it->second;

	Digit result = add(fibo(index - 1), fibo(index - 2));
	memo[index] = result;
	return result;
}

Digit add(Digit a, Digit b){
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	Digit result; //Will be added into constantly
	Digit & other = a; //Will add into the result

	// This condition is for, finding out which one is gonna be added into, ofc it should be the one
	//with more digits
	if (a.size() <= b.size()){
		 result = b;
		 other = a;
	}
	else {
		result = a;
		other = b;
	}

	// if number overflows, we will add carry to the other digit
	int carry = 0;

	for(size_t i = 0; i < result.size(); ++i){
		if(i < other.size())
			result[i] += other[i];

		result[i] += carry;

		if(result[i] >= 10){
			carry = 1;
			result[i] -= 10;
		} else {
			carry = 0;
		}
	}

	// Last overflow
	if(carry != 0) result.push_back(carry);

	reverse(result.begin(), result.end());
	return result;
}





