// Created on: Dec 27, 2020 by Alireza
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int ways(int target, vector<int>::iterator coin);

int main(int argc, char **argv) {
	vector<int> units = { 1, 2, 5, 10, 20, 50, 100, 200 };
	vector<int>::iterator it = find(units.begin(), units.end(), 200);

	cout << ways(200,it) << endl;
	return 0;
}

// Description : Recursive Solution
// If we have target as 5 and the greatest coin to be broken into as 5
// We have one 5coin and none of the smaller ones
// Or we have zero 5coins and the smaller ones
// The same goes for smaller ones
// Base : If coin is equal to 1 : return 1
map<pair<int,int>,int> memo;
int ways(int target, vector<int>::iterator coin) {
	if (*coin <= 1 || target == 0)
		return 1;
	int result = 0;
	auto it = memo.find(pair<int,int>{target,*coin});
	if(it != memo.end()) return it-> second;
	while (target >= 0) {
		result += ways(target, coin - 1);
		target = target - *coin;
	}
	memo.insert({{target, *coin}, result});
	return result;
}
