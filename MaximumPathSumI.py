#!/usr/bin/python3

def main():
    print(PathSum(ConvertToList(), 0, 0))
        
def PathSum(lst, level = 0, preIndex = 0, memo = {}):
    test = 0
    if level >= len(lst):
        return 0
    for number, item in LevelGenerator(lst[level]):
       
        print(level, number, item)
        if preIndex == number or preIndex + 1 == number:
            test += PathSum(lst, level + 1, number)
    else:
        return test
    
def LevelGenerator(lst):
    counter = 0
    while counter < len(lst):
        yield counter, lst[counter]
        counter += 1

def ConvertToList(fileName = 'MaximumPathSumI.txt'):
    result = list()
    file = open(fileName)
    for item in file.readlines():
        item = item.replace(' ', '')
        item = item.replace('\n','')
        numberList = list()
        for number in item:
            numberList.append(int(number))
        else:
            result.append(numberList)
            
    return result

if __name__ == "__main__": main()