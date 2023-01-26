import sys

sys.stdin = open("input.txt", "r")

n, m = map(int, input().split())

result = 0

for _ in range(n):
  arr = list(map(int, input().split()))
  arr.sort()
  min = arr[0]
  if result < min:
    result = min

print(result)
