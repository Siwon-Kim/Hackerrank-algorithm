# DFS
import sys
sys.stdin = open("input.txt", "r")

n, m = map(int, input().split())

graph = []
for i in range(n):
    graph.append(list(map(int, input())))

def dfs(x, y):
    if x <= -1 or x >= n or y <= -1 or y >= m:
        return False
    
    # vertex not visited
    if graph[x][y] == 0:
        graph[x][y] = 1 # mark as visited
        # call recursively NSWE
        dfs(x - 1, y)
        dfs(x + 1, y)
        dfs(x, y - 1)
        dfs(x, y + 1)
        return True
    # vertex already visited
    return False

count = 0
for i in range(n):
    for j in range(m):
        if dfs(i, j) == True:
            count += 1

print(count)