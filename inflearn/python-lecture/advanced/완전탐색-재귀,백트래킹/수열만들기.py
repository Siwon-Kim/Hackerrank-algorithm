import sys
input = sys.stdin.readline

n, m = map(int, input().split())

# 반복문
for i in range(1, n+1):
    for j in range(i+1, n+1):
        print(i, j)