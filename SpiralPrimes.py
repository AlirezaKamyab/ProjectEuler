#!/usr/bin/env python3
# This file is written by Alireza Kamyab
# Asnwer to projecteuler.net/problem=58

def main():
    add = 2
    num = 1
    primes = 0
    diagonals = 1

    while True:
        num += add
        if isPrime(num): primes += 1
        diagonals += 1

        num += add
        if isPrime(num): primes += 1
        diagonals += 1

        num += add
        if isPrime(num): primes += 1
        diagonals += 1

        num += add
        if isPrime(num): primes += 1
        diagonals += 1

        add += 2

        if (primes / diagonals) * 100 < 10: break

    print(add - 2 + 1)

def isPrime(n : int):
    if n <= 1: return False
    if n < 4: return True
    if n % 2 == 0: return False
    if n < 9: return True
    if n % 3 == 0: return False

    cnt = 1
    limit = 0
    while limit * limit <= n:
        limit = cnt * 6
        if n % (limit + 1) == 0: return False
        if n % (limit - 1) == 0: return False
        cnt += 1

    return True

if __name__ == "__main__": main()