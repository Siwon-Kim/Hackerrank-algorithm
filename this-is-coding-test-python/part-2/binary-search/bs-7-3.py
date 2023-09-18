# parametric search
# 원하는 조건을 만족하는 가장 알맞은 값을 찾는 문제


N, M = map(int, input().split())
height = list(map(int, input().split()))

result = 0
start = 0
end = max(height)

while start <= end:
    mid = (start + end) // 2
    sum = 0
    for i in height:
        if i - mid > 0:
            sum += i - mid
    if M > sum:
        end = mid - 1
    else:
        result = mid
        start = mid + 1

print(result)
