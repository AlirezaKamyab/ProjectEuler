//Created on: Dec 21, 2020 by Alireza
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

bool isPrime(int number);
vector<int> PrimeDivisions(int number, int power);
bool isExisted(vector<int> main, vector<vector<int>> list);

int main(int argc, char ** argv){
	vector<vector<int>> answers;
	for(int i = 2; i <= 100; ++i){
		for(int j = 2; j <= 100; ++j){
			vector<int> item = PrimeDivisions(i, j);
			if(isExisted(item, answers) == false){
				answers.push_back(item);
			}
		}
		cout << "base " << i << " calculated" << endl;
	}

	cout << "The answer is " << answers.size() << endl;
	return 0;
}

vector<int> PrimeDivisions(int number, int power){
	vector<int> temp;
	if(isPrime(number)){
		for(int pwr = 0; pwr < power; pwr++){
			temp.push_back(number);
		}
		return temp;
	}

	for(int i = 2; i <= ceil(number / 2); i++){
		if(isPrime(i)){
			int n = number;
			while(n % i == 0){
				for(int repeat = 0; repeat < power; repeat++) temp.push_back(i);
				n /= i;
			}
		}
	}
	return temp;
}

bool isPrime(int number){
	if(number <= 1) { return false; }
	for(int i = 2; i < (int)sqrt(number) + 1; i++){
		if(number % i == 0){
			return false;
		}
	}
	return true;
}

bool isExisted(vector<int> main, vector<vector<int>> list){
	for(vector<int> item : list){
		if(item.size() != main.size()) continue;
		for(int number : main){
			auto res = find(item.begin(),item.end(), number);
			if(res != item.end()){
				item.erase(res);
				continue;
			}
			else{
				break;
			}
		}
		if(item.size() == 0){
			return true;
		}
		else{
			continue;
		}
	}
	return false;
}
