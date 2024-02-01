# 점화식

# top-down 재귀함수 => for 반복문 점화식

N = int(input())
schedules = [list(map(int, input().split())) for _ in range(N)] # [period, pay]

dp = [0 for _ in range(N+1)]

for idx in range(N)[::-1]: # 역순으로 반복문
    if idx + schedules[idx][0] > N:
        dp[idx] = dp[idx+1]
    else:
        dp[idx] = max(dp[idx+schedules[idx][0]] + schedules[idx][1], dp[idx+1])

print(dp[0])
