#!/usr/bin/python3
def main():
    LongestChain = 0
    answer = 0
    for number in range(500000,1000000):
        count = countCollatzChain(number)
        if count > LongestChain:
            LongestChain = count
            answer = number
    else:
        print("The LongestChain is", LongestChain, 'produced by', answer)

memo = {}
def countCollatzChain(n):
    if n == 1:
        return 1

    if n in memo:
        return memo[n]
    
    if n % 2 == 0:
        result = 1 + countCollatzChain(n / 2)
        memo[n] = result
        return result
    else:
        result = 1 + countCollatzChain(3 * n + 1)
        memo[n] = result
        return result
    
if __name__ == '__main__': main()