#!/usr/bin/python3

def main():
    number = 600851475143
    print(GreatestPrimeFactor(number))
    
def GreatestPrimeFactor(number):
    lastFactor = 0
    if number % 2 == 0:
        number = number / 2
        lastFactor = 2
        while number % 2 == 0:
            number /= 2
    else:
        lastFactor = 1

    factor = 3
    while number > 1 and factor * factor <= number:
        if number % factor == 0:
            number /= factor
            lastFactor = factor
            while number % factor == 0:
                number /= factor
        factor += 2

    if number == 1:
        return lastFactor
    else: return number

if __name__ == "__main__":main()
