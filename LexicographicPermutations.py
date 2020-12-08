#!/usr/bin/python3

def main():
    numbers = [0,1,2,3,4,5,6,7,8,9]
    answerList = Permutation(numbers, len(numbers))
    answerList = StringListToIntList(answerList)
    print("The answer is: ", answerList[999999])

def Permutation(numList = [], length = 10, res = "", memo = set()):
    innerNumList = [i for i in numList]
    result = res
    for num in numList:
        result += str(num)
        innerNumList.remove(num)
        Permutation(innerNumList, length, result, memo)
        result = res
        innerNumList = [i for i in numList]
    else:
        if result not in memo and len(result) == length:
            memo.add(result)
    
    return memo

def StringListToIntList(NumberSet = set()):
    lst = [i for i in NumberSet]
    counter = 0
    while counter < len(lst):
        lst[counter] = int(lst[counter])
        counter +=1
        
    return sorted(lst)

if __name__ == "__main__": main()