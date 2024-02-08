#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double max_res = 0;
    int max_line = 0;
    for(int i = 0; i < 1000; i++) {
        int n, p;
        cin >> n >> p;

        double res = p * log10(n);
        if(res > max_res) {
            max_res = res;
            max_line = i + 1;
        }
    }

    cout << max_line << endl;
    return 0;
}