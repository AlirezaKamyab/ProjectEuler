#!/usr/bin/python3

import math

def main():
    num = longest = 1
    for n in range(3, 1000, 2): #No even values, to prevent from infinite iteration (Why?)
        #My guess is, only prime numbers as denominator make the greatest length for the cycle, which even numbers and
        #5 are not allowed here and therefore, our answer is a prime number
        if not isPrime(n):#Not Prime numbers are skipped due to the fact above
            continue

        if n % 5 == 0:
            continue

        p = 1
        while (10 ** p) % n != 1:
            p += 1

        if p > longest:
            num, longest = n, p

    print(num)

def isPrime(number):
    if number == 1:
        return False
    for i in range(2, int(math.sqrt(number)) + 1):
        a = number // i
        if number % i == 0 or number % a == 0:
            return False
    else:
        return True

if __name__ == "__main__": main()
