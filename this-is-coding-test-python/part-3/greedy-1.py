import sys
sys.stdin = open('input.txt', 'r')

n = int(input())
ppl = list(map(int, input().split()))
numOfGroup = 0
count = 0

ppl.sort()
for p in ppl:
    count += 1
    if count >= p:
        numOfGroup += 1
        count = 0

print(numOfGroup)