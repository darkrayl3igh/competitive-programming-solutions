'''
Problem: https://www.hackerrank.com/challenges/designer-pdf-viewer/problem
'''

#!/bin/python3

import math
import os
import random
import re
import sys
import string

def designerPdfViewer(h, word):
    ind = []
    ans = []
    for i in word:
        e = (string.ascii_lowercase.index(i))
        ind.append(e)
    for j in ind:
        ans.append(h[j])
    return(max(ans) * len(ans))


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    h = list(map(int, input().rstrip().split()))

    word = input()

    result = designerPdfViewer(h, word)

    fptr.write(str(result) + '\n')

    fptr.close()
