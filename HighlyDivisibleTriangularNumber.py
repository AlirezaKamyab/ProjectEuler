#!/usr/bin/python3
import math
def main():
    for number in TriangularGenerator():
        count = countDivisions(number)
        print(number,"---",count)
        if count > 500:
            print("The answer is", number)
            break

def TriangularGenerator():
    counter, result = 1, 0
    while True:
        result += counter
        counter += 1
        yield result
        
def countDivisions(number):
    counter, numberofDivisions = 1, 0
    while counter <= int(math.sqrt(number)):
        if number % counter == 0:
            numberofDivisions += 2
        counter += 1
    else:
        return numberofDivisions

if __name__ == '__main__': main()