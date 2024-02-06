n = int(input())
arr = sorted(list(map(int, input().split())))
x = int(input())

s, e = 0, n-1
count = 0

while s < e:
    if arr[s] + arr[e] == x:
        count += 1
    if arr[s] + arr[e] >= x:
        e -= 1
    else:
        s += 1

print(count)
