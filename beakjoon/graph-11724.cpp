#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <cstring>

using namespace std;

vector<int> connected[1001];
bool visited[1001];

void bfs(int start) {
  queue<int> q;
  visited[start] = true;
  q.push(start);

  while(!q.empty()) {
    int current = q.front();
    q.pop();
    int q_size = connected[current].size();
    
    for(int i=0; i<q_size; i++) {
      int next = connected[current][i];
      if(!visited[next]) {
        visited[next] = true;
        q.push(next);
      }
    }
  }
}

int main() {
  // freopen("input.txt", "rt", stdin);
  int N, M;
  cin >> N >> M;
  for(int i=0; i<M; i++) {
    int u, v;
    cin >> u >> v;
    connected[u].push_back(v);
    connected[v].push_back(u);
  }

  int count = 0;
  memset(visited, false, sizeof(visited));
  for(int i=1; i<=N; i++) {
    if(!visited[i]) {
      bfs(i);
      count++;
    }
  }
  cout << count << endl;
}
