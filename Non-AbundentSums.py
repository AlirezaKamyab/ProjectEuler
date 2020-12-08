#!/usr/bin/python3
import math

def main():
    limit = 28124
    print('loading abundents . . .')
    listOfabundents = list_of_abundent(limit)
    length = len(listOfabundents)
    print('loading answers . . .')
    answers = set(range(1,limit))
    for i, n in enumerate(listOfabundents):
        counter = i
        sumation = 0
        while counter < length and sumation < limit:
            sumation = n + listOfabundents[counter]
            if sumation in answers:
                answers.remove(sumation)
            counter += 1
    
    print('the answer is', sum(answers))

def proper_divisors_sum(number):
    result = 1
    for n in range(2, (int(math.sqrt(number))) + 1):
        if number % n == 0:
            result += n
            if number // n != n:
                result += number // n
    return result

def isAbundent(number):
    if proper_divisors_sum(number) > number:
        return True
    else: return False

    
def list_of_abundent(limit):
    lst = list()
    for number in range(1, limit):
        if isAbundent(number):
            lst.append(number)
    return lst
if __name__ == '__main__': main()