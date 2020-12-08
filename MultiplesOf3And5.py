#!/usr/bin/python3

def main():
    counter = 1
    answer = 0
    while counter < 1000:
        if counter%3 == 0 or counter % 5 == 0:
            answer += counter
        counter += 1
        
    print("The answer is", answer)

if __name__ == "__main__": main()