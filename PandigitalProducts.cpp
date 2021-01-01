//Created on: Jan 1, 2021 by Alireza
#include<iostream>
#include<set>
using namespace std;

bool isPandigital(int a , int b);
int length(int a);

template<typename t>
t sum(set<t> nums);

int main(int argc, char ** argv){
	set<int> answers;
	for(int i = 1; true; i++){
		if(i % 10 == 0) continue; // 0 is not considered as a member of Pandigitals
		if(length(i) > 4) break; // If I gets to be 5 digits, minimum digit of identity and product will be 11
		for(int j = 1; true; j++){
			if(length(i) + length(j) + length(i*j) >= 10) break;
			if(isPandigital(i, j)){
				answers.insert(i*j);
			}
		}
	}

	cout << "The answer is " << sum<int>(answers) << endl;
	return 0;
}

bool isPandigital(int a , int b){
	string strNumbers = to_string(a * b) + to_string(a) + to_string(b);
	size_t length = strNumbers.length();
	set<int> numbers;
	if(a % 10 == 0 || b % 10 == 0) return false;
	for(char i : strNumbers){
		int n = i - '0';
		if (n == 0) return false;
		pair<set<int>::iterator, bool> result;
		result = numbers.insert(n);
		if(!result.second) return false;
	}
	if(numbers.size() != length){
		return false;
	}

	set<int> target = {1,2,3,4,5,6,7,8,9};
	if(target != numbers) return false;

	return true;
}

// Returns an integer representing how many digits does a number have
int length(int a){
	int counter = 0;
	while(a >= 1){
		counter++;
		a /= 10;
	}

	return counter;
}

// returns an integer of sum of all the numbers in a set
template<typename t>
t sum(set<t> nums){
	int summation = 0;
	for(t i : nums){
		summation += i;
	}
	return summation;
}
