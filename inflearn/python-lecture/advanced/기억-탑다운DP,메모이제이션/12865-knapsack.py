import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

# item의 위치와 무게를 index로 하는 2차원 list dp 테이블에 누적 value 값을 저장해서 기억한다

def recur(cur, w):
    global ans
    if w > weight_limit:
        return -9999999
    
    if cur == n:
        return 0
    
    if dp[cur][w] != -1:
        return dp[cur][w]
    
    dp[cur][w] = max(recur(cur+1, w + arr[cur][0]) + arr[cur][1], recur(cur + 1 , w))

    return dp[cur][w]


n, weight_limit = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]

dp = [[-1 for _ in range(100_001)] for _ in range(n)] # 2차원 리스트 -> 무게 & 선택 물건 개수 트래킹 

print(recur(0, 0))