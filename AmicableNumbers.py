#!/usr/bin/python3

def main():
    results = {}
    answers = list()
    for i in range(0, 10000):
        for k,v in Amicable(i).items():
            results[k] = v
    
    for k, v in results.items():
        if v == True:
            answers.append(k)
            
    print("These are Amicable numbers", answers)
    print("Sum of them is", sum(answers))

def Amicable(number, memo = {}):
    if number < 10000:
        if number not in memo:
            a = sumation(number)
            b = sumation(a)
            
            if b == number and number != a:
                memo[number] = True
                memo[a] = True
            else:
                memo[number] = False
                Amicable(a, memo)
    return memo

def sumation(number):
    s = 0
    for n in range(1, (number // 2) + 1):
        if number % n == 0:
            s += n
    
    return s
if __name__ == "__main__": main()