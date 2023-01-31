n = int(input())
arr = list(map(int, input().split()))

m = [0] * 101

# base cases
m[0] = arr[0]
m[1] = max(arr[0], arr[1])

# bottom-up
for i in range(2, n):
  m[i] = max(m[i-1], m[i-2]+arr[i])

print(m[n-1])
