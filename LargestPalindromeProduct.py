#!/usr/bin/Python3

def main():
    i, j = 999, 999
    largestPalindrome = 0
    while i >= 100:
        if i % 11 == 0:
            j = 999
            db = 1
        else:
            j = 990 #divsible by 11
            db = 11
            
        while j >= i:
            if i * j < largestPalindrome:
                break

            if i * j == getReverse(i * j):
                largestPalindrome = i * j

            j -= db
        i -= 1
    print(largestPalindrome)


def getReverse(number):  # Returns a reversed number of the number given as parameter
    result = 0
    while number >= 1:
        result = (result * 10) + (number % 10)
        number = number // 10
    else:
        return result


if __name__ == "__main__": main()
