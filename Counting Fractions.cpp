#include <iostream>
using namespace std;

void generate_phi(int* arr, const int& limit);
constexpr int LIMIT = 1e6 + 1;
int arr[LIMIT];

int main() {
    generate_phi(arr, LIMIT);
    int64_t cnt = 0;
    for(int i = 2; i < LIMIT; i++) cnt += arr[i];
    cout << cnt << endl;
    return 0;
}

void generate_phi(int* arr, const int& limit) {
    for(int i = 0; i < limit; i++) arr[i] = i;

    for(int i = 2; i < limit; i++) {
        if(arr[i] == i) arr[i] = i - 1;
        else continue;

        for(int j = 2 * i; j < limit; j += i) {
            arr[j] = arr[j] - arr[j] / i;
        }
    }
}