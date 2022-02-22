#!/bin/python

import math
import os
import random
import re
import sys

#
# Complete the 'luckBalance' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER k
#  2. 2D_INTEGER_ARRAY contests
#

def luckBalance(k, contests):
    # Write your code here
    balance = 0   
    imp_list = []
    
    for i in range(n):
        l, t = contests[i]
        if t == 0:
           balance += l 
        else:    
            imp_list.append(l)
    imp_list.sort()
    
    if len(imp_list) > k:
        for i in range(len(imp_list)-k):
            balance -= imp_list[i]
        for i in range(len(imp_list)-k, len(imp_list)):
            balance += imp_list[i]
    else:
        for i in range(len(imp_list)):
            balance += imp_list[i]
    
    return balance
       

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = raw_input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    contests = []

    for _ in xrange(n):
        contests.append(map(int, raw_input().rstrip().split()))

    result = luckBalance(k, contests)

    fptr.write(str(result) + '\n')

    fptr.close()
