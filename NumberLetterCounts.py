#!/usr/bin/python3

def main():
    answer = 0
    for number in range(1,1001):
        inLetter = ToLetter(number)
        answer += len(inLetter)
        print(inLetter, number)
    else:
        print("--------------------------\nThe answer is {}\n--------------------------".format(answer))

def ToLetter(number):
    dictionary = {0: "", 1:"One", 2:"Two", 3: 'Three', 4:'Four', 5: 'Five', 6:'Six', 7:'Seven', 8: 'Eight', 9: 'Nine', 10: 'Ten', 11: 'Eleven', 12: 'Twelve', 13: 'Thirteen',
                  15:'Fifteen', 18:"Eighteen", 20: 'Twenty', 30: 'Thirty', 40: 'Forty', 50: 'Fifty', 60: 'Sixty', 70: 'Seventy', 80: 'Eighty', 90: 'Ninety', 1000: 'OneThousand'}
    
    if number in dictionary:
        return dictionary[number]
    
    if number not in dictionary and number > 13 and number < 20:
        return dictionary[number % 10] + "Teen"
    
    if number not in dictionary and number > 20:
        result = ''
        if number < 100:
            result = dictionary[number - (number % 10)] + dictionary[number % 10]
        else:
            temp = (number // 100) * 100
            result = ToLetter(number - temp)
        
        if number // 100 >= 1:
            temp = dictionary[number // 100] + 'Hundred'
            if len(result) > 0:#If these line prevents the result from being OneHundredAnd or . . . Instead returns OneHundred
                result = temp + "And" + result
            else:
                result = temp + result
        return result

if __name__ == "__main__": main()