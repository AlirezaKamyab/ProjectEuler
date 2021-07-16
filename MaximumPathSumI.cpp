#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void findPath(int** A, const int l);

// Converting file to array
void makeArray(int** numbers, const string fileName = "MaximumPathSumI.txt");
void addRow(int** numbers, const int n, const string value);
int convertToNumber(const string value);
int countRows(const string fileName = "MaximumPathSumI.txt");

int MAX_ROWS = countRows();

int main(){
    int** A = new int*[MAX_ROWS];
    for(int i = 0; i < MAX_ROWS; i++) A[i] = new int[i + 1];

    makeArray(A);
    findPath(A, MAX_ROWS - 1);
    cout << A[0][0] << endl;

    for(int i = 0; i < 4; i++) delete[] A[i];
    delete[] A;
    return 0;
}

void findPath(int** A, const int l){
    if(l == 0){
        return;
    }

    for(int i = 0; i < l; i++){
        if(A[l][i] >= A[l][i + 1]) A[l - 1][i] += A[l][i];
        else A[l - 1][i] += A[l][i + 1];
    }
    findPath(A, l - 1);
}

void makeArray(int** numbers, const string fileName){
    fstream stream;
    stream.open(fileName, ios::in);
    int row = 0;
    if(stream.is_open()){
        string strnum;
        while(getline(stream, strnum)){
            addRow(numbers, row++, strnum);
        }
        stream.close();
    }
}

int countRows(const string fileName){
    fstream stream;
    stream.open(fileName, ios::in);
    int row = 0;
    if(stream.is_open()){
        string strnum;
        while(getline(stream, strnum)){
            row++;
        }
        stream.close();
    }
    return row;
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