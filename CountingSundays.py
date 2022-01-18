#!/usr/bin/env python3
# This file is written by Alireza Kamyab
# answer to problem projecteuler.net/problem=19

class Date:
    MONTHS = ('January', 'February', 'March', 'April', 'May', 'June', 'July', 'Aguest', 'September', 'Obtober', 'November', 'December')
    DAYS = ('Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Satruday', 'Sunday')

    def __init__(self, **kwargs):
        self._day = kwargs['day'] if 'day' in kwargs else 1
        self._month = kwargs['month'] if 'month' in kwargs else 1
        self._year = kwargs['year'] if 'year' in kwargs else 1900
        self._dayindex = None

    def day(self, value = None):
        if value != None: 
            self._day = value
            self._dayindex = None

        return self._day
    
    def month(self, value = None):
        if value != None: 
            self._month = value
            self._dayindex = None

        return self._month

    def year(self, value = None):
        if value != None: 
            self._year = value
            self._dayindex = None

        return self._year

    def add_one_day(self):
        self._day += 1
        if self._dayindex != None: self._dayindex = (self._dayindex + 1) % 7

        if Date.day_of_month(self._month, self._year) < self._day:
            self._day = 1
            self._month += 1
            
            if self._month > 12:
                self._year += 1
                self._month = 1
    
    def days_between(self, date):
        if date > self: return date.days_between(self)

        temp = Date(day = date.day(), month = date.month(), year = date.year())
        cnt = 0
        while temp != self:
            temp.add_one_day()
            cnt += 1
        return cnt

    def what_day(self):
        if self._dayindex != None: return self.DAYS[self._dayindex]

        cnt = self.days_between(Date(day=1, month=1, year=1900))
        self._dayindex = cnt % 7
        return self.DAYS[self._dayindex]

    def what_month(self):
        return self.MONTHS[self._month - 1]

    def compare(self, other):
        if self._day < other._day: return -1
        elif self._day > other._day: return 1
        else:
            if self._month < other._month: return -1
            elif self._month > other._month: return 1
            else:
                if self._year < other._year: return -1
                elif self._year > other._year: return 1
                else: return 0

    def __eq__(self, other):
        return self.compare(other) == 0
    
    def __ne__(self, other):
        return not self == other

    def __lt__(self, other):
        return self.compare(other) == -1
    
    def __le__(self, other):
        res = self.compare(other)
        return res == -1 or res == 0
    
    def __gt__(self, other):
        return self.compare(other) == 1
    
    def __ge__(self, other):
        res = self.compare(other)
        return res == 0 or res == 1

    def __str__(self):
        return f"{self.what_day()}, {self.what_month()} {self._day}, year {self._year}"


    @staticmethod
    def day_of_month(month, year):
        if month == 9 or month == 4 or month == 6 or month == 11: return 30
        elif month == 2: return 28 if not Date.is_leap_year(year) else 29
        else: return 31

    @staticmethod
    def is_leap_year(year):
        if year % 100 == 0:
            return year % 400 == 0
        
        return year % 4 == 0

    @staticmethod
    def string_to_date(string : str):
        lst = [int(x) for x in string.split('/')]
        res = Date(day=lst[0], month=lst[1], year=lst[2])
        return res

    

def main():
    start = Date(day=1, month=1, year=1901)
    end = Date(day=31, month=12, year=2000)

    cnt = 0
    while start != end:
        if start.day() == 1 and start.what_day() == 'Sunday': cnt += 1
        start.add_one_day()
    
    print(cnt)

if __name__ == '__main__' : main()