#!/usr/bin/Python3

def main():
    counter = 0
    for prime in PrimeGenerator():
        counter += 1
        print("#{}: {}".format(counter, prime)) #Since it takes a little while, it is good to track the counter
        if counter == 10001:
            print("The Answer is", prime)
            break

def isPrime(number):
    if number == 1:
        return False
    for item in range(2, number):
        if number % item == 0:
            return False
    else: return True
    
def PrimeGenerator(): #Generates prime number infinitely unless, it is stopped out of the function
    counter = 1
    while True:
        if isPrime(counter): yield counter
        counter += 1

if __name__ == "__main__": main()