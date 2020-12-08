#!/usr/bin/Python3

def main():
    i,j = 100,100
    answer = 0
    while i < 1000:
        while j < 1000:
            if i*j == getReverse(i*j) and i*j > answer:
                answer = i * j
            j += 1
        else:
            j = 100
            i += 1
    else:
        print("The answer is {}".format(answer))

def getReverse(number): #Returns a reversed number of the number given as parameter
    result = 0
    while number >= 1:
        result = (result * 10) + (number % 10)
        number = number // 10
    else:
        return result

if __name__ == "__main__": main()