// This file is written by Alireza Kamyab 3/28/2021
// If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, 
// there are exactly three solutions for p = 120. {20, 48, 52}, { 24,45,51 }, { 30,40,50 }
// For which value of p ≤ 1000, is the number of solutions maximised ?
#include <iostream>
#include <cmath>
using namespace std;

int AllRightTriangles(int perimeter);

int main() {
	int max_solutions = 0;
	int max_perimeter = 1;
	for (int i = 1; i <= 10000; i++) {
		int solution = AllRightTriangles(i);
		if (solution > max_solutions) {
			max_solutions = solution;
			max_perimeter = i;
		}
	}

	cout << max_perimeter << endl;
	return 0;
}

int AllRightTriangles(int perimeter) {
	// Using Dickson's Method (r^2 = 2st)
	// Then a, b for two sides and c for hypotenuse will be r + s, r + t and r + s + t
	// Dickson's method is easily proved using Pythagorean theorm
	// This makes the perimeter be 3 * r + 2 * s + 2 * t
	int counter = 0;
	for (int r = 2; r <= perimeter / 3; r+=2) {
		int number = (r * r) / 2;
		for (int s = 1; s <= int(sqrt(number)); s++) {
			if (number % s != 0) continue;
			int t = number / s;
			if (3 * r + 2 * s + 2 * t == perimeter) counter++;
		}
	}
	return counter;
}