#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 1001

using namespace std;

int N, M;
int graph[MAX][MAX];
int isVisited[MAX][MAX];
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
queue<pair<int, int>> q;

void bfs() {
  while(!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for(int i=0; i<4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
      if(graph[ny][nx] == 0 && isVisited[ny][nx] == -1) {
        isVisited[ny][nx] = isVisited[y][x] + 1;
        q.push(make_pair(ny, nx));
      }
    }
  }
}

int main() {
  // freopen("input.txt", "rt", stdin);
  cin >> M >> N;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin >> graph[i][j]; 
      isVisited[i][j] = -1;
      if(graph[i][j] == 1) {
        q.push(make_pair(i, j));
        isVisited[i][j] = 0;
      }
    }
  }
  bfs();

  int result = 0;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      if(graph[i][j] == 0 && isVisited[i][j] == -1) {
        cout << -1 << endl;
        return 0;
      }
      result = max(result, isVisited[i][j]);
    }
  }
  cout << result << endl;
  return 0;
}
