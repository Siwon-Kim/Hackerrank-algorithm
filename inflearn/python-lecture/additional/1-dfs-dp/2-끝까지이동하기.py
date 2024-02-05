import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

Y, X = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(Y)]
dp = [[-1 for _ in range(X)] for _ in range(Y)]
count = 0

def recur(y, x):
    if dp[y][x] != -1: # 모든 지점 중에서 한 번이라도 지나갔다면 재사용
        return dp[y][x]
    
    if y == Y - 1 and x == X - 1: # 목적지에 도착했을 때만 1을 리턴
        return 1

    route = 0    
    for dy, dx in [[0,1], [0,-1], [1,0], [-1,0]]:
        ey = y + dy
        ex = x + dx

        if 0 <= ey < Y and 0 <= ex < X:
            if graph[y][x] > graph[ey][ex]:
                route += recur(ey, ex)
    dp[y][x] = route  
    return dp[y][x]

print(recur(0, 0))
