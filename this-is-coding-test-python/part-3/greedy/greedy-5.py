import sys
sys.stdin = open('input.txt', 'r')
from itertools import combinations

n, m = map(int, input().split())
weights = list(map(int, input().split()))

answer = 0

for p in list(combinations(weights, 2)):
    if p[0] != p[1]:
        answer += 1
    
print(answer)