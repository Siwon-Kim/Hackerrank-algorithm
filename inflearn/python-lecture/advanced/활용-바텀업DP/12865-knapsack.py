import sys
input = sys.stdin.readline

n, weight_limit = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]

dp = [[-1 for _ in range(100_001)] for _ in range(n)] # 2차원 리스트 -> 무게 & 선택 물건 개수 트래킹 

for idx in range(n):
    for weight in range(weight_limit+1):
        if weight > weight_limit:
            dp[idx][weight] = dp[idx-1][weight]
        else:
            dp[idx][weight] = max(dp[idx-1][weight-arr[idx][0]] + arr[idx][1], dp[idx-1][weight])

print(max(dp[n-1]))