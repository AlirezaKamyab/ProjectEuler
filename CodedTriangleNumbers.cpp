// This file is created by Alireza Kamyab 3/30/2021
// Solution to problem projecteuler.net/problem=42
#include <iostream>
#include <cstdio>
#include <regex>
#include <vector>
#include <cmath>
using namespace std;

/// <summary>
/// Reads a txt file and returns the text from the file into a string
/// </summary>
string readFile(const char* FILENAME);

/// <summary>
/// Question's given words are surrounded by " ". This function returns a vector of words that used to be between
/// quotations
/// </summary>
vector<string> matchWords(string text);

/// <summary>
/// Returns the number of the character in alphabets
/// </summary>
int getEnglishCode(string word);

/// <summary>
/// Checks wether a number is triangular and returns a boolean
/// </summary>
bool isTriangularNumber(int number);

int main() {
	int counter = 0;
	string text = readFile("CodedTriangleNumbers.txt");
	vector<string> words = matchWords(text);
	
	for (string word : words) {
		if (isTriangularNumber(getEnglishCode(word))) counter++;
	}

	cout << counter << endl;
	return 0;
}

bool isTriangularNumber(int number) {
	// 1/2 n(n + 1) = number
	// n^2 + n - 2number = 0; if this equation has any root that is integer, it should be a triangular number
	int delta = 1 + (8 * number);
	if (delta < 0) return false;
	
	float positiveRoot = (float)((-1) + sqrt(delta)) / 2;
	if ((int)positiveRoot != positiveRoot) return false;

	return true;
}

int getEnglishCode(string word) {
	int code = 0;
	for (char c : word) {
		code += c - 'A' + 1;
	}
	return code;
}

vector<string> matchWords(string text) {
	vector<string> result;

	regex pattern("\"[A-Z]+\"");
	smatch match;
	while (regex_search(text, match, pattern)) {
		for (auto item : match) {
			string temp = item;
			temp.erase(temp.begin());
			temp.pop_back();
			result.push_back(temp);
		}
		text = match.suffix().str();
	}

	return result;
}

string readFile(const char* FILENAME) {
	const int MAX_BUFFER = 128000;
	char* buffer = new char[MAX_BUFFER];

	FILE* fr = fopen(FILENAME, "r");
	fgets(buffer, MAX_BUFFER, fr);

	fclose(fr);
	return buffer;
}