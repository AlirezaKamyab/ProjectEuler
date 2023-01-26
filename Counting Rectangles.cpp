#include <iostream>
#include <cmath>
using namespace std;

int number_of_rectangles(const int&, const int&);

int main() {
    int minr = 0, minc = 0;
    int min_diff = INT32_MAX;
    for(int r = 1; r <= 2000; r++) {
        for(int c = 1; c <= 2000; c++) {
            int rec_num = number_of_rectangles(r, c);
            if(abs(2000000 - rec_num) < min_diff) {
                min_diff = abs(2000000 - rec_num);
                minr = r;
                minc = c;
            }
        }
    }

    cout << minr * minc << endl;
    return 0;
}


int number_of_rectangles(const int& r, const int& c) {
    // For making a rectangle we need 2 horizontal lines and 2 vertical lines; So we choose 2 from r times
    // choose 2 from c --> number of rectangles = (r * (r + 1)) / 2  times (c * (c + 1)) / 2
    return r * (r + 1) * c * (c + 1) / 4;
}