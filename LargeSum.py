#!/usr/bin/python3

def main():
    print(str(Sumation('LargeSum.txt'))[0:10])

def Sumation(filename):#Large numbers are in a file named "LargeSum.txt"
    file = open(filename)
    result = 0
    for line in file.readlines():
        result += int(line)
        
    return result

if __name__ == "__main__": main()