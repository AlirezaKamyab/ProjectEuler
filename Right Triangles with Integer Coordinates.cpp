#include <iostream>
#include <cmath>
using namespace std;

float distance (const int& x1, const int& y1, const int& x2, const int& y2)
{
    return ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
}

bool isRightTriangle (const int& x1, const int& y1, const int& x2, const int& y2)
{
    // If OP is Hypotenuse
    if (distance(x2,y2,0,0) + distance(x1,y1,x2,y2) == distance(x1,y1,0,0))
        return true;
    // If OQ is Hypotenuse
    if (distance(x1,y1,0,0) + distance(x1,y1,x2,y2) == distance(x2,y2,0,0))
        return true;
    // If PQ is Hypotenuse
    if (distance(x2,y2,0,0) + distance(x1,y1,0,0) == distance(x1,y1,x2,y2))
        return true;

    return false;
}

constexpr int LIMIT = 50;
int arr[LIMIT+1][LIMIT+1][LIMIT+1][LIMIT+1] = {0};

int main()
{
    int cnt = 0;
    for (int x1 = 0; x1 <= LIMIT; x1++)
        for (int y1 = 0; y1 <= LIMIT; y1++)
            for (int x2 = 0; x2 <= LIMIT; x2++)
                for (int y2 = 0; y2 <= LIMIT; y2++)
                {
                    if(x1 == x2 && y1 == y2) continue;
                    if ((x1 == 0 && y1 == 0) || (x2 == 0 && y2 == 0)) continue;
                    if (arr[x1][y1][x2][y2] == 1) continue;
                    if(arr[x2][y2][x1][y1] == 1) continue;
                    arr[x1][y1][x2][y2] = 1;
                    if (isRightTriangle(x1,y1,x2,y2))
                        cnt++;
                }
    cout << cnt;

    return 0;
}