n, m = map(int, input().split())
graph = [list(map(int, input())) for _ in range(n)]
count = 0

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def bfs(x, y):
  queue = deque()
  queue.append((x, y))

  while queue:
    x, y = queue.popleft()
    for i in range(4):
      xx = x + dx[i]
      yy = y + dy[i]
      if xx < 0 or yy < 0 or xx >= n or yy >= m:
        continue
      if graph[xx][yy] == 0:
        continue
      if graph[xx][yy] == 1:
        graph[xx][yy] = graph[x][y] + 1
        queue.append((xx, yy))

  return graph[n - 1][m - 1]

print(bfs(0, 0))
