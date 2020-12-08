#!/usr/bin/python3
def main():
    LongestChain = 0
    answer = 0
    for number in range(500000,1000000):
        count = CountCollatzChain(number)
        print(number,'---', count)
        if count > LongestChain:
            LongestChain = count
            answer = number
    else:
        print("The LongestChain is", LongestChain, 'produced by', answer)

def Collatz(number):
    if number % 2 == 0:
        return number // 2
    else:
        return (number * 3) + 1
    
def CountCollatzChain(number):
    counter = 0
    while number != 1:
        number = Collatz(number)
        counter += 1
    else:
        return counter + 1 #The actual number is not counted through the iteration so we added one in here
    
if __name__ == '__main__': main()