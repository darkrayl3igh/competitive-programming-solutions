'''
Problem: https://www.hackerrank.com/challenges/apple-and-orange/problem
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'countApplesAndOranges' function below.
#
# The function accepts following parameters:
#  1. INTEGER s
#  2. INTEGER t
#  3. INTEGER a
#  4. INTEGER b
#  5. INTEGER_ARRAY apples
#  6. INTEGER_ARRAY oranges
#

def countApplesAndOranges(s, t, a, b, apples, oranges):
    # Write your code here
    count_a, count_o = 0, 0
    apple = []
    orange = []
    for i in apples:
        elea = i + a
        apple.append(elea)
    for j in oranges:
        eleo = j + b
        orange.append(eleo)
    # print(apple, orange) 
    
    for i in apple:
        if i in range(s, t+1):
            count_a = count_a+1

    for j in orange:
        if j in range(s, t+1):
            count_o = count_o+1
    print(count_a)
    print(count_o)

if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()

    s = int(first_multiple_input[0])

    t = int(first_multiple_input[1])

    second_multiple_input = input().rstrip().split()

    a = int(second_multiple_input[0])

    b = int(second_multiple_input[1])

    third_multiple_input = input().rstrip().split()

    m = int(third_multiple_input[0])

    n = int(third_multiple_input[1])

    apples = list(map(int, input().rstrip().split()))

    oranges = list(map(int, input().rstrip().split()))

    countApplesAndOranges(s, t, a, b, apples, oranges)
