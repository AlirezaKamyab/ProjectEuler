#!/usr/bin/python3
import math

primeList = [2]


def main():
    for i in primeGenerator():
        if(i > 10000):
            break
        primeList.append(i)

    i = 0
    counter = 1
    t = 1
    while counter <= 500:
        counter = 1
        i += 1
        t = TriangularNumber(i)
        tt = t
        for p in primeList:
            if p**2 > tt:
                counter *= 2
                break
            
            exponent = 1
            while tt % p == 0:
                exponent += 1
                tt = tt / p
            else:
                if exponent > 1: counter *= exponent
                if tt == 1: break
    else:
        print(t)

def TriangularNumber(n):
    return (n * (n + 1)) // 2


def isPrime(n):
    if n == 1:
        return False
    if n < 4:
        return True
    if n % 2 == 0:
        return False
    if n < 9:
        return True
    if n % 3 == 0:
        return False
    f = 5
    r = math.floor(math.sqrt(n))
    while f <= r:
        if(n % f == 0):
            return False
        if(n % (f + 2) == 0):
            return False
        f += 6
    else:
        return True


def primeGenerator():
    counter = 3
    while True:
        if(isPrime(counter)):
            yield counter
        counter += 2


if __name__ == '__main__':
    main()
