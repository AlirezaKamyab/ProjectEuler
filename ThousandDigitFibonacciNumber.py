#!/usr/bin/python3

def main():
    for i in range(10000):
        answer = Fibonacci(i)
        if len(str(answer)) == 1000:
            print("The number is: ",answer)
            print("The index is: ", i)
            break

memo = dict()
def Fibonacci(level):
    if level == 1 or level == 2:
        return 1
    
    if level < 1:
        return 0
    
    if level in memo:
        return memo[level]
    
    answer = Fibonacci(level - 1) + Fibonacci(level - 2)
    if answer not in memo.values():
        memo[level] = answer
    
    return answer

if __name__ == "__main__": main()