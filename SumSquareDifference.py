#!/usr/bin/python3

def main():
    number = 100
    SumSquare = SumOfSquares(number)
    SquareSum = SquareOfSums(number)
    print("The answer is {}".format(abs(SumSquare - SquareSum)))

def SumOfSquares(number = 100):
    return (number * (number + 1) * (2 * number + 1)) / 6
    
def SquareOfSums(number = 100):
    sums = (number * (number + 1)) / 2
    return sums * sums

if __name__ == "__main__": main()