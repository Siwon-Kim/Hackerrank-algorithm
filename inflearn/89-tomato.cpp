#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int tomato[1001][1001], ripe[1001][1001], res = -2147000000;

struct Loc{
	int x;
	int y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}
};

queue<Loc> Q;

int main() {
  ios_base::sync_with_stdio(false);
  freopen("input.txt", "rt", stdin);
  int n, m;
  cin >> m >> n;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      cin >> tomato[i][j];
      if(tomato[i][j]==1) Q.push(Loc(i, j));
    }
  }

  while(!Q.empty()) {
    Loc tmp = Q.front();
    Q.pop();
    for(int i=0; i<4; i++) {
      int xx=tmp.x+dx[i];
      int yy=tmp.y+dy[i];
      if(tomato[xx][yy]==0 && xx>=1 && xx<=n && yy>=1 && yy<=m) {
        Q.push(Loc(xx, yy));
        tomato[xx][yy]=1;
        ripe[xx][yy] = ripe[tmp.x][tmp.y]+1;
      }
    }
  }

  int flag=1;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      if(tomato[i][j]==0) {
        flag=0;
      }
    }
  }
  if(flag==1) {
    for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) {
        if(res<ripe[i][j]) {
          res=ripe[i][j];
        }
      }
    }
    cout << res;
  }
  else cout << -1;
  
	return 0;
}
