import sys
input = sys.stdin.readline

n, m = map(int, input().split())

# 반복문
for i in range(1, n+1):
    for j in range(i, n+1):
        print(i, j)

print("\n\n")

# 재귀함수
def recur(i, n):
    if i > n:
        return
    
    for j in range(i, n+1):
        print(i, j)

    recur(i+1, n)

arr = []
recur(1, n)