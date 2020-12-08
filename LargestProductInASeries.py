#!/usr/bin/python3

def main():
    leng = 13
    counter = 0
    answer = 0
    numberFile = open('HugeNumber.txt') #This file holds the huge number on a line
    line = numberFile.readline()
    while counter < len(line):
        cuttedNumber = line[counter:counter + leng] #This is a string holding a number selected from text
        if len(cuttedNumber) == leng:
            if Multiple(cuttedNumber) > answer:
                answer = Multiple(cuttedNumber)
        counter += 1
    else:
        print('The Answer is ', answer)
    
def Multiple(numberAsString):
    result = 1
    for item in numberAsString:
        result *= int(item)
    else:
        return result
    
if __name__ == "__main__": main()