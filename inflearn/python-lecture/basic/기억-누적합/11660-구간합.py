n, m = map(int, input().split())

graph = [list(map(int, input().split())) for _ in range(n)]
target = [list(map(int, input().split())) for _ in range(m)]

prefix = [[0 for _ in range(n+1)] for _ in range(n+1)] # 2차원 배열 초기화 하기 
# prefix = [[0] * (n+1) for _ in range(n+1)]

# 2차원 배열 누적합 만들기
for x in range(n):
    for y in range(n):
        prefix[x+1][y+1] = graph[x][y] + prefix[x+1][y] + prefix[x][y+1] - prefix[x][y]

# 원하는 좌표들의 합 계산하기
for i in range(m):
    x1, y1, x2, y2 = target[i]
    result = prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1]
    print(result)
