#!/usr/bin/python3
from math import sqrt

def main():
    print("The answer is", PrimeSummation())

def PrimeSummation():
    primes = list()
    for n in range(2, 2000000): 
        print(n)
        for prime in primes:
            if n % prime == 0 : break #Every non-prime number is either divisible by a prime number
            if int(sqrt(n) < prime):  #Or by a prime less than square root of the number
                primes.append(n)
                break
        else:
            primes.append(n)
    else:
        return sum(primes)
        
if __name__ == "__main__": main()