#!/usr/bin/python3

def main():
    summ = 0
    for number in FibonacciGenerator(1, 2):
        if number % 2 == 0:
            summ += number
            
    print("The answer is {}".format(summ))
    
def FibonacciGenerator(a,b):
    while a < 4000000:
        yield a
        a,b = b, a + b

if __name__ == "__main__": main()