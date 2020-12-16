//Created on: Dec 16, 2020 by Alireza Kamyab
#include<iostream>
using namespace std;

int RightBottomDiagonal(int n);
int LeftBottomDiagonal(int n);
int RightTopDiagonal(int n);
int LeftTopDiagonal(int n);
int DiagonalsSumation(int n);

int main(int argc, char ** argv){
	cout << "The answer is " << DiagonalsSumation(1001) << endl;
	return 0;
}

int CountDiagonals(int n){
	return ((n - 1) / 2) + 1;
}

int RightBottomDiagonal(int n){
	int count = CountDiagonals(n);
	int sum = 0;
	int number = 1;
	int add = 2;
	for(int i = 0; i < count; ++i){
		sum += number;
		number += add + (8 * i);
	}
	return sum;
}

int LeftBottomDiagonal(int n){
	int count = CountDiagonals(n);
	int sum = 0;
	int number = 1;
	int add = 4;
	for(int i = 0; i < count; ++i){
		sum += number;
		number += add + (8 * i);
	}
	return sum;
}

int LeftTopDiagonal(int n){
	int count = CountDiagonals(n);
	int sum = 0;
	int number = 1;
	int add = 6;
	for(int i = 0; i < count; ++i){
		sum += number;
		number += add + (8 * i);
	}
	return sum;
}


int RightTopDiagonal(int n){
	int count = CountDiagonals(n);
	int sum = 0;
	int number = 1;
	int add = 8;
	for(int i = 0; i < count; ++i){
		sum += number;
		number += add + (8 * i);
	}
	return sum;
}

int DiagonalsSumation(int n){
	int answer = 1;
	answer += RightBottomDiagonal(n);
	answer += RightTopDiagonal(n);
	answer += LeftBottomDiagonal(n);
	answer += LeftTopDiagonal(n);
	return answer;
}

