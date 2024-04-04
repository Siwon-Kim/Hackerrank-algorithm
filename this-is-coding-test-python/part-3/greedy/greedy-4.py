import sys
sys.stdin = open('input.txt', 'r')

N = int(input())
coins = list(map(int, input().split()))
coins.sort()

target = 1
for c in coins:
    if target < c:
        break
    target += c

print(target)
