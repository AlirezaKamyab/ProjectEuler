// This file is written by Alireza Kamyab
// Answer to the problem projecteuler.net/problem=44
#include <iostream>
#include <cmath>
using namespace std;

int pentagon(int n);
bool isPentagon(int p);

int main(){
	int minDifference = -1;
	for(int k = 1; k < 5000; k++){
		int pk = pentagon(k);
		for(int j = k - 1; j > 0; j--){
			int pj = pentagon(j);
			int pi = pk - pj;
			if(isPentagon(pi) && isPentagon(pj - pi)){
				if(minDifference > pj - pi || minDifference == -1){
					minDifference = pj - pi;
				}
			}
		}
	}

	cout << minDifference << endl;
	return 0;
}

bool isPentagon(int p){
	int delta = 1 + (4 * 3 * 2 * p);
	if(delta < 0) return false;

	float a =((1) + sqrt(delta)) / (2 * 3);
	if(int(a) == a) return true;
	else return false;
}

int pentagon(int n){
	return (n * (3 * n - 1)) / 2;
}