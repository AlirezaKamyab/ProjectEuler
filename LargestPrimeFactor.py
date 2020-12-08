#!/usr/bin/python3

def main():
    number = 600851475143
    print(GreatestPrimeFactor(number))

def SmallestPrimeFactor(number):
    for i in range(2, int(number)): #For faster iteration use the range (2, sqrt(number) + 1) (Why?)
        if number % i == 0:
            return i
    else:
        return number
    
def GreatestPrimeFactor(number):
    while True:
        smallest = SmallestPrimeFactor(number)
        if number > smallest:
            number = number / smallest
        else: return number

if __name__ == "__main__":main()
