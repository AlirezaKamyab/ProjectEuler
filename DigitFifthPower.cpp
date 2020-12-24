//Created on: Dec 24, 2020 by Alireza
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> Search(int power);
int DigitPower(int number, int power);
int CountDigits(int number);
int FirstNDigit(int n);
int MaxNumber(int power);

int main(int argc, char ** argv){
	vector<int> powerDigits = Search(5);
	int sumation = 0;

	for(int number : powerDigits){
		sumation += number;
		cout << number << endl;
	}

	cout << "The answer is " << sumation << endl;
	return 0;
}

vector<int> Search(int power){
	vector<int> results;
	int counter = 2;
	int max = MaxNumber(power);
	while(counter < max){
		int calculation = DigitPower(counter, power);
		if(calculation == counter){
			results.push_back(counter);
		}
		counter++;
	}
	return results;
}

int DigitPower(int number, int power){
	string temp = to_string(number);
	int answer = 0;
	for(char num : temp){
		int n = (int)num - '0'; //converting char to int
		answer += (int)pow(n, power);
	}
	return answer;
}

int CountDigits(int number){
	int counter = 0;
	while (number >= 1){
		number = number / 10;
		counter++;
	}

	return counter;
}

int FirstNDigit(int n){
	int number = 1;
	for(int i = 1; i < n; i++){
		number *= 10;
	}

	return number;
}

int MaxNumber(int power){
	int base = pow(9,power);
	int counter = 0;
	while(true){
		int calc = counter * base;
		if(CountDigits(calc) < counter){
			break;
		}
		counter++;
	}

	return FirstNDigit(counter) - 1;
}


