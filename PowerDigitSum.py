#!/usr/bin/python3

def main():
    answer = 0
    for char in Power(2, 1000):
        answer += int(char)
        
    print(answer)

def Power(number, power):
    return str(number ** power)
if __name__ == "__main__": main()