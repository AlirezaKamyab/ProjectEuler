#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int findPath(int**, const int, int, int = 0, int = 0, int = 0);
int findAll(int** A, const int l);

void makeArray(int** numbers, const int n, string fileName = "MaximumPathSumI.txt");
void addRow(int** numbers, const int n, const string value);
int convertToNumber(const string value);

const int MAX_ROWS = 15;

int main(){
    int** A = new int*[MAX_ROWS];
    for(int i = 0; i < MAX_ROWS; i++){
        A[i] = new int[i + 1];
    }

    makeArray(A, MAX_ROWS);
    cout << findAll(A, MAX_ROWS - 1) << endl;
    

    for(int i = 0; i < 4; i++) delete[] A[i];
    delete[] A;
    return 0;
}

int findPath(int** A, const int l, int n, int previousN, int sum, int maxSum){
    sum += A[l][n];

    // Base cases
    if(n < previousN - 1 || n > previousN) return maxSum;
    if(n > l || n < 0) return maxSum;
    if(l == 0){
        if(maxSum < sum) maxSum = sum;
        return maxSum;
    }

    // Recursive
    if(maxSum < sum) maxSum = sum;
    int a = findPath(A, l - 1, n, n, sum, maxSum);
    int b = findPath(A, l - 1, n - 1, n, sum, maxSum);
    if(a > b) return a;
    if(b > a) return b;
    return a;
}

int findAll(int** A, const int l){
    int max = 0;
    for(int i = 0; i < l; i++){
        int temp = findPath(A, l, i, i);
        if(max < temp) max = temp;
    }

    return max;
}

void makeArray(int** numbers, const int n, string fileName){
    fstream stream;
    stream.open(fileName, ios::in);
    int row = 0;
    if(stream.is_open()){
        string strnum;
        while(getline(stream, strnum)){
            addRow(numbers, row++, strnum);
        }
    }
    stream.close();
}

void addRow(int** numbers, const int n, const string value){
    for(int i = 0; i <= n; i++){
        string sub = value.substr(3 * i, 3);
        int number = convertToNumber(sub);
        numbers[n][i] = number;
    }
}

int convertToNumber(const string value){
    int number = 0;
    int multiplier = 1;
    for(int i = 0; i < value.length(); i++){
        int converted = value[i] - '0';
        if(!(converted >= 0 && converted <= 9)) continue;;
        number = (number * multiplier) + (converted % 10);
        multiplier *= 10;
    }
    return number;
}