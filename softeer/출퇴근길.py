import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6) # WARNING!! 까먹지 말기

def dfs(graph, curr, visited):
    if visited[curr] == 1:
        return
    visited[curr] = 1
    for neighbor in graph[curr]:
        dfs(graph, neighbor, visited)
    return

if __name__=="__main__":
    n, m = map(int, input().split())
    graph = [[] for _ in range(n+1)] 
    reversed_graph = [[] for _ in range(n+1)] 
    for _ in range(m):
        v, e = map(int, input().split())
        graph[v].append(e)
        reversed_graph[e].append(v)
    s, t = map(int, input().split())
    
    fromS = [0] * (n+1)
    fromS[t] = 1 # t를 미리 방문한 것으로 세팅해서 t를 방문하는 순간 탐색을 종료
    dfs(graph, s, fromS)
    
    fromT = [0] * (n+1)
    fromT[s] = 1 
    dfs(graph, t, fromT)
    
    toS = [0] * (n+1)
    dfs(reversed_graph, s, toS)
    
    toT = [0] * (n+1)
    dfs(reversed_graph, t, toT)
    
    count = 0
    
    for i in range(1, n+1):
        if fromS[i] and fromT[i] and toS[i] and toT[i]:
            count += 1
    
    print(count-2) # s, t vertices는 제외하기