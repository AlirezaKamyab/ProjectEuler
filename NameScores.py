#!/usr/bin/python3

import re

def main():
    scores = list()
    names_list = get_list()
    for index, name in enumerate(names_list):
        scores.append(get_aphabatical_score(name, index + 1))
    print('The answer is {}'.format(sum(scores)))

def get_list(filename = 'NameScore.txt'):
    file = open(filename)
    total = file.read()
    pattern = re.compile('\"')
    if re.search(pattern, total):
        total = pattern.sub('', total)
    lst = total.split(',')    
    return sorted(lst)

def get_aphabatical_score(name, position):
    score = 0
    alpha_list = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
    for i in name.lower():
        score += alpha_list.index(i) + 1
    return score * (position)
    
if __name__ == '__main__': main()