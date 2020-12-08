#!/usr/bin/python3

def main():
    answer = 0
    for item in Getday(31, 12, 2000):
        if item[0] == 6 and item[3] >= 1901 and item[1] == 1:
            answer += 1
            
    print(answer)
def Getday(targetDate = 1, targetMonth = 1, targetYear = 1900):
    #translate = ['Monday','Tuesday','Wednesday','Thursday','Friday','Saturday','Sunday']
    day, date, month ,year = 0, 1, 1, 1900
    while year < targetYear or month < targetMonth or date < targetDate:
        yield (day, date, month, year)
        if day == 6: day = 0
        else: day += 1
        
        maxDates = MonthDates(month, year)
        if date == maxDates:
            date = 1
            if month == 12:
                month = 1
                year += 1
            else:
                month += 1
        else:
            date += 1

def MonthDates(Month, Year):
    if Month == 4 or Month == 6 or Month == 9 or Month == 11:
        return 30
    elif Month == 2:
        if isLeapYear(Year): return 29
        else:
            return 28
    else:
        return 31      
    
def isLeapYear(Year):
    if Year % 100 != 0:
        if Year % 4 == 0:
            return True
        else:
            return False
    else:
        if Year % 400 == 0:
            return True
        else:
            return False
        
if __name__ == "__main__": main()