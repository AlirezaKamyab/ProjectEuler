#include <iostream>
#include <vector>
using namespace std;

const int LIMIT = 28124;

int sumOfDivisors(int number);
int sumOfProperDivisors(const int& number);
void listOfAbundentNumbers(vector<int>& vec, const int& limit);
bool isAbundent(const int& number);
int binarySearch(const vector<int>& vec, const int& n);

int main() {
    bool* numbers = new bool[LIMIT + 1] {false};
    vector<int> abundentList;
    listOfAbundentNumbers(abundentList, LIMIT);

    int summation = 0;
    for(int i = 0; i < abundentList.size(); i++){
        for(int j = i; j < abundentList.size(); j++){
            int newNumber = abundentList[i] + abundentList[j];
            if(newNumber > LIMIT) break;
            if(numbers[newNumber] == false) numbers[newNumber] = true;
        }
    }

    for(int i = 0; i < LIMIT + 1; i++) {
        if(numbers[i] == false) summation += i;
    }

    cout << summation << endl;

    delete[] numbers;
    return 0;
}

int sumOfDivisors(int number){
    int p = 2;
    int sum = 1;

    while(p * p <= number && number > 1){
        if(number % p == 0){
            int j = p * p; // maximum p^n that could possibly be multiple of the prime
            number = number / p;

            while(number % p == 0){
                j = j * p;
                number = number / p;
            }

            sum *= (j - 1);
            sum /= (p - 1);
        }

        if(p == 2) p = 3; else p += 2;
    }

    if(number > 1) sum = sum * (number + 1);
    return sum;
}

int sumOfProperDivisors(const int& number){
    return sumOfDivisors(number) - number;
}

bool isAbundent(const int& number){
    return (sumOfProperDivisors(number) > number)? true : false;
}

void listOfAbundentNumbers(vector<int>& vec, const int& limit){
    for(int i = 1; i < limit; i++){
        if(isAbundent(i)) vec.push_back(i);
    }
}

int binarySearch(const vector<int>& vec, const int& n){
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] == n) return i;
    }
    return -1;
}