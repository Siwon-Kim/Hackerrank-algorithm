#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1001

int n, m, v;
vector<int> graph[MAX];
bool visited[MAX];
queue<int> q;

void DFS(int start, vector<int> graph[], bool visited[]) {
  visited[start] = true;
  cout << start << " ";
  for(int i=0; i<graph[start].size(); i++) {
    int next = graph[start][i];
    if(visited[next] == false) {
      DFS(next, graph, visited);
    }
  }
}

void BFS(int start) {
  q.push(start);
  visited[start] = true;
  cout << start << " ";

  while(!q.empty()) {
    int tmp = q.front();
    q.pop();
    for(int i=0; i<graph[tmp].size(); i++) {
      int next = graph[tmp][i];
      if(visited[next] == false) {
        q.push(next);
        visited[next] = true;
        cout << next << " ";
      }
    }
  }
}

void reset() {
  for(int i=1; i<=n; i++) {
    visited[i] = false;
  }
}

int main() {
  // freopen("input.txt", "rt", stdin);
  cin >> n >> m >> v;
  for(int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for(int i=1; i<=n; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  DFS(v, graph, visited);
  cout << "\n";
  reset();
  BFS(v);
}
