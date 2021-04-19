#!/usr/bin/env python3

from math import sqrt, ceil

def main():
    sum = 1000
    print(multipleOfPythagorean(sum))

def multipleOfPythagorean(sum):
    limit = ceil(sqrt(sum)) - 1
    
    for m in range(2, limit):
        if sum % (2 * m) == 0:
            sm = sum / (2 * m)

            while sm % 2 == 0: sm /= 2
            k = m + 1 if m % 2 == 0 else m + 2
            while k < 2 * m and k <= sm:
                if sm % k == 0 and gcd(m, k) == 1:
                    d = sm / k
                    n = k - m
                    a = (m ** 2 - n ** 2) * d
                    b = 2 * m * n * d
                    c = d * (m ** 2 + n ** 2)

                    return a * b * c
                k += 2

def gcd(a, b):
    if a == 1 or b == 1: return 1
    if a % b == 0: return b
    if b % a == 0: return a

    if a > b: return gcd(a % b, b)
    else: return gcd(a, b % a)

if __name__ == "__main__": main()