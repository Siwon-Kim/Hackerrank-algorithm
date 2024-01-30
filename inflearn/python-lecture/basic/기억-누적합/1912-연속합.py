n = int(input())
array = list(map(int, input().split()))

prefix = [0 for _ in range(n)]
prefix[0] = array[0]

for i in range(1, n):
    prefix[i] = max(prefix[i-1] + array[i], array[i])


print(max(prefix))