import sys
input = sys.stdin.readline

n = int(input())
rocks = list(map(int, input().split()))
dp = [1] * n
        
for i in range(1, n):
    max_result = 0
    for j in range(i):
        if rocks[j] < rocks[i]:
            max_result = max(max_result, dp[j])
    dp[i] = max_result + 1  
print(max(dp))