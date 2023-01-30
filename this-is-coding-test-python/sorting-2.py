n = int(input())
arr = []
for _ in range(n):
  arr.append(int(input()))

arr = sorted(arr, reverse=True)

for i in arr:
  print(i, end=' ')
