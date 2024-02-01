import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

def solve_topdown_dp(idx):
    if idx > n+1:
        return -999999999
    if idx == n+1:
        return 0
    
    if dp[idx] == -1: # 이미 dp 테이블에 저장되어 있는 경우
        return dp[idx]

    # 상담을 받거나, 안받거나, 그 중에서 더 많은 돈을 버는 경우를 내 DP 테이블에 저장하겠다
    dp[idx] = max(solve_topdown_dp(idx+options[idx][0]) + options[idx][1], solve_topdown_dp(idx+1))
    return dp[idx]

n = int(input())
# index 1부터 값 넣기
options = [[] for _ in range(n+1)]
for i in range(n):
    t, p = map(int, input().split())
    options[i+1] = [t, p]

# memoization용 리스트 만들기
dp = [-1 for _ in range(n+1)]

max_salary = solve_topdown_dp(1)
print(max_salary)