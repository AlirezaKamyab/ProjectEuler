#!/usr/bin/python3

def main():
    print(LatticePath(20,20))

def LatticePath(m,n, memo={}):
    if m == 0 or n == 0:
        return 1
    
    if (m, n) in memo.keys():
        return memo[(m, n)]
    
    result = LatticePath(m - 1, n) + LatticePath(m, n - 1)
    memo[(m , n)] = result
    return result

if __name__ == "__main__": main()