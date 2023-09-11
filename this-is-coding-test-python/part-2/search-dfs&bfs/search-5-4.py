import sys
sys.stdin = open("input.txt", "r")

from collections import deque

n, m = map(int, input().split())

maze = []
for i in range(n):
    maze.append(list(map(int, input())))

# N S W E
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y):
    queue = deque()
    queue.append((x, y))

    # until the queue is empty
    while queue:
        x, y = queue.popleft()

        # check all 4-direction
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            # if outside of the maze
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue

            # if encountering the wall
            if maze[nx][ny] == 0:
                continue

            # if first visited vertex
            if maze[nx][ny] == 1:
                maze[nx][ny] += maze[x][y]
                queue.append((nx, ny))

    return maze[n - 1][m - 1]

print(bfs(0, 0))