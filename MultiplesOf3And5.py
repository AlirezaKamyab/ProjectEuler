#!/usr/bin/env python3

import math

def main():
    limit = 999
    print(sumOfMultiples(3, limit) + sumOfMultiples(5, limit) - sumOfMultiples(15, limit))

def sumOfMultiples(n, max):
    return n * (math.floor(max / n) * (math.floor(max / n) + 1)) / 2

if __name__ == "__main__": main()