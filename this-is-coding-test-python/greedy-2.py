import sys

sys.stdin = open("input.txt", "r")

n, m, k = map(int, input().split())
data = list(map(int, input().split()))

data.sort()
first = data[n-1]
second = data[n-2]

cnt = 0
result = 0
for _ in range(m):
  if cnt == k:
    result += second
    cnt = 0
  else:
    result += first
    cnt += 1

print(result)
