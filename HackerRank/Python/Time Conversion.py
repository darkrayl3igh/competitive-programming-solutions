'''
Ques: https://www.hackerrank.com/challenges/time-conversion/submissions/code/221953931
'''



#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    # Write your code here
    time = s.split(':')
    print(time)
    time[2] = time[2].replace('M', '')
    aorp = time[2][2]
    time[2] = time[2].replace(time[2][2], '')
    if (aorp == 'P'):
        if (time[0] == '12'):
            return(':'.join(time))
        else:
            time[0] = str(int(time[0]) + 12)
            print(time)
            return(':'.join(time))
    elif(aorp == 'A'):
        if (time[0] == '12'):
            time[0] = '0' + str(int(time[0]) - 12)
            print(time)
        return(':'.join(time))
        
        
            
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
