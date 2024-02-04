#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

void generate_prime(bool* prime, const int& limit)
{ 
    for (int i = 0; i < (limit - 1) / 2; i++)
        prime[i] = true;
    prime[0] = false;
    for (int i = 1; i * i <= (limit - 1) / 2; i++)
        if (prime[i])
            for (int j = 2 * i * (i + 1); j <= (limit - 1) / 2; j += 2 * i + 1)
                prime[j] = false;
}

bool isprime(const int& x, const bool* prime)
{
    if (x < 2) return false;
    else if (x == 2) return true;
    else if ((x % 2) == 0) return false;
    else if (prime[(x - 1) / 2]) return true;
    else return false;
}

constexpr int MAX_PRIMES = 10000000;
bool primes[MAX_PRIMES];
constexpr int LIMIT = 50000000;

int main() {
    unordered_map<int, bool> map;
    generate_prime(primes, MAX_PRIMES);
    cout << "Primes generated" << endl;
    int cnt = 0;

    for(int c = 2; pow(c, 4) < LIMIT; c++) {
        if(!isprime(c, primes)) continue;
        for(int b = 2; pow(c, 4) + pow(b, 3) < LIMIT; b++) {
            if(!isprime(b, primes)) continue;
            for(int a = 2; pow(c, 4) + pow(b, 3) + pow(a, 2) < LIMIT; a++) {
                if(!isprime(a, primes)) continue;
                if(map[pow(c, 4) + pow(b, 3) + pow(a, 2)]) continue;
                map[pow(c, 4) + pow(b, 3) + pow(a, 2)] = true;
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}