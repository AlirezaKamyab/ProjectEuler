#!/usr/bin/python3

def main():
    limit = 4000000
    sum = 0
    fibo = 0

    counter = 1
    while fibo < limit:
        sum += fibo
        fibo = even_fibonacci(counter)
        counter += 1
    print(sum)
def even_fibonacci(n):
    if n == 1: return 2
    if n < 1: return 0

    return 4 * (even_fibonacci(n - 1)) + even_fibonacci(n - 2)

if __name__ == "__main__": main()