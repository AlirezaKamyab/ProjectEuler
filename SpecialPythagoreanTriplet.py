#!/usr/bin/python3
from math import sqrt

def main():
    print('The answer is',GetABC())

def isPythagorean(a,b,c):
    if c ** 2 == a**2 + b ** 2:
        return True
    else:
        return False
    
def GetABC():
    c = 0
    for a in range(1, 1001):
        for b in range(1, 1001):
            if a + b > 1000: break #To reduce processing time remove useless data 
            c = int(sqrt(a **2 + b **2))
            if a + b + c == 1000 and isPythagorean(a, b, c):
                print(a,b,c)
                return a*b*c

if __name__ == "__main__": main()