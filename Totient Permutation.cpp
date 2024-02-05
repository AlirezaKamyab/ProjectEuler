#include <iostream>
using namespace std;

void generate_phi(int* arr, const int& limit);
bool is_permutation(int a, int b);

constexpr int LIMIT = 1e7 + 1;
int arr[LIMIT];

int main() {
    generate_phi(arr, LIMIT);
    float min = LIMIT;
    int min_n = LIMIT;
    for(int i = 2; i < LIMIT; i++) {
        if(!is_permutation(i, arr[i])) continue;
        if(i / (float)arr[i] < min) {
            min = i / (float)arr[i];
            min_n = i;
        }
    }

    cout << min_n << endl;
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

bool is_permutation(int a, int b) {
    int arr_a[10] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int arr_b[10] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while(a) {
        arr_a[a % 10]++;
        a /= 10;
    }

    while(b) {
        arr_b[b % 10]++;
        b /= 10;
    }

    for(int i = 0; i < 10; i++) {
        if(arr_a[i] != arr_b[i]) return false;
    }
    
    return true;
}