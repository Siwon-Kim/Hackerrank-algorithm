n = int(input())

arr = []
for i in range(n):
    arr.append(int(input()))

result = sorted(arr, reverse=True)

for i in range(n):
    print(result[i], end=" ")