#!/usr/bin/python3

def main():
    counter = getMultiplesOfPrime(20)
    filterDevision = getMultiplesOfPrime(20)
    while True:
        if counter % filterDevision != 0:
            counter += 1
            continue
        print(counter)
        for d in range(1,21):
            if counter % d != 0:
                counter += 1
                break
        else:
            print("The answer is", counter)
            break

def isPrime(number):
    if number == 1:
        return False
    for n in range(2, number):
        if number % n == 0:
            return False
    else:
        return True
       
def PrimeGenerator():
    counter = 1
    while True:
        if isPrime(counter): yield counter
        counter += 1
        
def getMultiplesOfPrime(maxDevision):
    number = 1
    for prime in PrimeGenerator():
        if prime <= maxDevision:
            number *= prime
        else:
            return number
        
if __name__ == "__main__":main()