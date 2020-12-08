#!/usr/bin/python3

def main():
    answer = 0
    digits = str(Factorial(100))
    for digit in digits:
        answer += int(digit)
    
    print("The answer is", answer)

def Factorial(n):
    if n == 1:
        return 1
    
    return n * Factorial(n - 1)

if __name__ == "__main__": main()