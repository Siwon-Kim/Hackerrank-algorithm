# Why recursion?
# => We can make it as a recurrence relation used in Dynamic Programming a lot

# DFS
# Node (Vertex) & Edge
# - adjacency matrix
# - adjacency list
# using stack (recursive function)
# insert just one adjancent vertex with priority
# remove from stack when there is no more adjancent vertex that is not visited

def dfs(graph, v, visited):
    # current vertex
    visited[v] = True
    
    # visit adjancent vertices using recusion
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

graph = [
    [],
    [2, 3, 8],
    [1, 7],
    [1, 4, 5],
    [3, 5],
    [3, 4],
    [7],
    [2, 6, 8],
    [1, 7]
]

visited = [False] * 9

dfs(graph, 1, visited)

# BFS
# using queue (deque library)
# usually BFS is faster than DFS

from collections import deque

def bfs(graph, start, visited):
    queue = deque([start])
    # current vertex
    visited[start] = True

    # until queue is empty
    while queue:
        v = queue.popleft()
        
        # insert unvisited & adjancent vertices of the current vertex 
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

bfs(graph, 1, visited)