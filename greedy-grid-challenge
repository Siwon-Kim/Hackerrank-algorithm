#!/bin/python

import math
import os
import random
import re
import sys

def gridChallenge(grid):
    for i in range(n):
        grid[i] = sorted(grid[i])

    for i in range(n-1):
        for j in range(n):
            if grid[i][j] > grid[i+1][j]:
                return "NO"
    return "YES"
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input().strip())

    for t_itr in xrange(t):
        n = int(raw_input().strip())

        grid = []

        for _ in xrange(n):
            grid_item = raw_input()
            grid.append(grid_item)

        result = gridChallenge(grid)

        fptr.write(result + '\n')

    fptr.close()
