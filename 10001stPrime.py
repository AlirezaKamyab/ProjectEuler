#!/usr/bin/env python3

from math import sqrt,floor

def main():
    counter = 0
    for prime in PrimeGenerator():
        counter += 1
        if counter == 10001:
            print("The Answer is", prime)
            break

def isPrime(number):
    if number <= 1 : return False
    if number < 4 : return True
    if number % 2 == 0 : return False
    if number < 9 : return True
    if number % 3 == 0 : return False

    k = 1
    limit = 0

    while limit * limit <= number :
        limit = k * 6
        if number % (limit + 1) == 0 : return False
        if number % (limit - 1) == 0 : return False
        k += 1
    
    return True
    
def PrimeGenerator(): #Generates prime number infinitely unless, it is stopped out of the function
    counter = 1
    while True:
        if isPrime(counter): yield counter
        counter += 1

if __name__ == "__main__": main()