import sys
input = sys.stdin.readline

n, h = map(int, input().split())

lines = [0 for _ in range(h)]

for p in range(n):
    height = int(input())
    if p % 2 == 0: # 짝수 인덱스 = 석순
        lines[0] += 1
        lines[height] -= 1
    else: # 홀수 인덱스 = 종유석
        lines[h-height] += 1

prefix = [0 for _ in range(h+1)]

for i in range(h):
    prefix[i+1] = prefix[i] + lines[i]

prefix = prefix[1:]

print(min(prefix), prefix.count(min(prefix)))