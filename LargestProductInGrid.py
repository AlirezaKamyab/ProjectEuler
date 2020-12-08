#!/usr/bin/python3
import time

def main():
    answer = 0
    temp = 0 #Keeps every calculated side, so when it is greater than answer, answer = temp
    matrix = ConvertToMatrix('LargestProductInGrid.txt') #The grid is kept in a txt file
    
    for row in range(0, len(matrix)):
        for column in range(0, len(matrix[0])):
            temp = CalculateLeftSide(row, column, matrix)
            if temp > answer:
                answer = temp
                print(row, column,"on LeftSide is the greatest product",answer)
            
            temp = CalculateRightSide(row, column, matrix)
            if temp > answer:
                answer = temp
                print(row, column,"on RightSide is the greatest product",answer)
                
            temp = CalculateTopSide(row, column, matrix)
            if temp > answer:
                answer = temp
                print(row, column,"on TopSide is the greatest product",answer)
                
            temp = CalculateBottomSide(row, column, matrix)
            if temp > answer:
                answer = temp
                print(row, column,"on BottomSide is the greatest product",answer)
                
            temp = CalculateDiagonalBottomLeft(row, column, matrix)
            if temp > answer:
                answer = temp
                print(row, column,"on DiagonalBottomLeftSide is the greatest product",answer)
                
            temp = CalculateDiagonalBottomRight(row, column, matrix)
            if temp > answer:
                answer = temp
                print(row, column,"on DiagonalBottomRightSide is the greatest product",answer)
                
            temp = CalculateDiagonalTopLeft(row, column, matrix)
            if temp > answer:
                answer = temp
                print(row, column,"on DiagonalTopLeftSide is the greatest product",answer)
                
            temp = CalculateDiagonalTopRight(row, column, matrix)
            if temp > answer:
                answer = temp
                print(row, column,"on DiagonalTopRightSide is the greatest product",answer)
            
    print("\n-------------------------\nFinal Answer is", answer,"\n-------------------------")
           
#The grid is kept in a txt File
def ConvertToMatrix(filename = 'LargestProductInGrid.txt'): #This function puts numbers into rows and columns like a matrix
    row = []
    file = open(filename)
    for line in file.readlines():
        column = []
        newLine = line.replace(' ','').replace('\n','')
        counter = 0
        while counter < len(newLine):
            cuttedText = newLine[counter: 2 + counter]
            if len(cuttedText) == 2:
                column.append(int(cuttedText))
            counter += 2
        else:
            row.append(column)
            
    else:
        return row
    
def CalculateLeftSide(row, column, matrix):
    if column - 3 >= 0:
        return matrix[row][column] * matrix[row][column - 1] * matrix[row][column - 2] * matrix[row][column - 3]
    else:
        return 0

def CalculateRightSide(row, column, matrix):
    if column + 3 < len(matrix):
        return matrix[row][column] * matrix[row][column + 1] * matrix[row][column + 2] * matrix[row][column + 3]
    else:
        return 0
    
def CalculateBottomSide(row, column, matrix):
    if row + 3 < len(matrix[0]):
        return matrix[row][column] * matrix[row + 1][column] * matrix[row + 2][column] * matrix[row + 3][column]
    else:
        return 0
    
def CalculateTopSide(row, column, matrix):
    if row - 3 > 0:
        return matrix[row][column] * matrix[row - 1][column] * matrix[row - 2][column] * matrix[row - 3][column]
    else:
        return 0
    
def CalculateDiagonalTopRight(row, column, matrix):
    if row - 3 >= 0 and column + 3 < len(matrix):
        return matrix[row][column] * matrix[row - 1][column + 1] * matrix[row - 2][column + 2] * matrix[row - 3][column + 3]
    else:
        return 0
    
def CalculateDiagonalBottomRight(row, column, matrix):
    if row + 3 < len(matrix[0]) and column + 3 < len(matrix):
        return matrix[row][column] * matrix[row + 1][column + 1] * matrix[row + 2][column + 2] * matrix[row + 3][column + 3]
    else:
        return 0
    
def CalculateDiagonalTopLeft(row, column, matrix):
    if row - 3 >= 0 and column - 3 >= 0:
        return matrix[row][column] * matrix[row - 1][column - 1] * matrix[row - 2][column - 2] * matrix[row - 3][column - 3]
    else:
        return 0
    
def CalculateDiagonalBottomLeft(row, column, matrix):
    if row + 3 < len(matrix[0]) and column - 3 >= 0:
        return matrix[row][column] * matrix[row + 1][column - 1] * matrix[row + 2][column - 2] * matrix[row + 3][column - 3]
    else:
        return 0
    
if __name__ == '__main__': main()