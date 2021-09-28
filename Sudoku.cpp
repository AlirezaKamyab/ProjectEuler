// This file is written by Alireza Kamyab
// Answer to projecteuler.net/problem=96
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readFromFile(const string& fileName);
bool solve(int gridNumber, int i, int j);
bool isValid(int gridNumber, int i, int j);

int table[50][9][9];
bool mark[50][9][9];

int main() {
    readFromFile("Sudoku.txt");

    int ans = 0;

    for(int i = 0; i < 50; i++) {
        solve(i, 0, 0);
        ans += (table[i][0][0] * 100) + (table[i][0][1] * 10) + table[i][0][2];
    }

    cout << ans << endl;
    return 0;
}

bool solve(int gridNumber, int i, int j) {
    if(i == 9) return true;
    if(j == 9) return solve(gridNumber, i + 1, 0);
    if(mark[gridNumber][i][j]) return solve(gridNumber, i, j + 1);

    for(int n = 1; n <= 9; n++) {
        table[gridNumber][i][j] = n;

        // Check for validation
        if(isValid(gridNumber, i, j)) {
            if(solve(gridNumber, i, j + 1)) return true;
        }

        table[gridNumber][i][j] = 0;
    }

    return false;
}

bool isValid(int gridNumber, int i, int j) {
    // Column validation
    for(int k = 0; k < 9; k++) {
        if(k == i) continue;
        if(table[gridNumber][i][j] == table[gridNumber][k][j]) return false;
    }

    // Row validation
    for(int k = 0; k < 9; k++) {
        if(k == j) continue;
        if(table[gridNumber][i][j] == table[gridNumber][i][k]) return false;
    }

    // Division validation
    int r = (i / 3) * 3;
    int c = (j / 3) * 3;
    
    for(int q = r; q < r + 3; q++) {
        for(int p = c; p < c + 3; p++) {
            if(q == i && p == j) continue;
            if(table[gridNumber][q][p] == table[gridNumber][i][j]) return false;
        }
    }

    return true;
}
 
void readFromFile(const string& fileName) {
    fstream file;
    file.open(fileName);
    if(file.is_open()) {
        string line;
        int row = 0;
        int tableNumber = -1;
        while(getline(file, line)) {
            // Ignoring "Grid XX"
            if(row % 10 == 0) {
                tableNumber++;
                row++;
                continue;
            }

            int col = 0;
            for(char c : line) {
                table[tableNumber][row % 10 - 1][col] = c - '0';
                if(c - '0' != 0) mark[tableNumber][row % 10 - 1][col] = true;
                col++;
            }

            row++;
        }
        file.close();
    }
}