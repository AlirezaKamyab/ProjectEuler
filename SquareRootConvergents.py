#!/usr/bin/env python3
# This file is written by Alireza Kamyab
# Answer to problem projecteuler.net/problem=57

def main():
    numerator = 3
    denominator = 2
    cnt = 0

    for i in range(1000 - 1):
        d = numerator + denominator
        n = d + denominator

        numerator, denominator = n, d

        if digits(numerator) > digits(denominator): cnt += 1

    print(cnt)


def digits(n : int):
    cnt = 0
    while n > 0:
        n //= 10
        cnt += 1

    return cnt

def gcd(a, b):
    if a == 1 or b == 1: return 1
    if a % b == 0: return b
    if b % a == 0: return a

    return gcd(b, a % b)

if __name__ == "__main__": main()