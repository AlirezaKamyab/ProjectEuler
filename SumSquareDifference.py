#!/usr/bin/python3

def main():
    MaxNumber = 100
    SumSquare = SumOfSquares(MaxNumber)
    SquareSum = SquareOfSums(MaxNumber)
    print("The answer is {}".format(abs(SumSquare - SquareSum)))

def SumOfSquares(MaxNumber = 100):
    counter = 1
    total = 0
    while counter <= MaxNumber:
        total += counter ** 2
        counter += 1
    else:
        return total
    
def SquareOfSums(MaxNumber = 100):
    counter = 0
    total = 0
    while counter <= MaxNumber:
        total += counter
        counter += 1
    else:
        return total ** 2

if __name__ == "__main__": main()