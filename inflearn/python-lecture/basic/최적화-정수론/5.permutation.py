import math
import sys

input = sys.stdin.readline

n = int(input())
arr = sorted(list(map(int, input().split())))

# find which parts need to insert the number
arr2 = []
count = 0
for i in range(len(arr) - 1):
    if math.gcd(arr[i], arr[i+1]) > 1:
        arr2.append([arr[i], arr[i+1]])

# find how many numbers should be inserted
# determine only 1 or 2

for a, b in arr2:
    for j in range(a+1, b):
        tmp = 0

        if math.gcd(a, j) == 1: tmp += 1
        if math.gcd(b, j) == 1: tmp += 1

        if tmp > 1:
            count += 1
            break
        if j == b - 1: # 끝까지 돌았는데 1개의 수가 없는 경우
            count += 2

print(count)
