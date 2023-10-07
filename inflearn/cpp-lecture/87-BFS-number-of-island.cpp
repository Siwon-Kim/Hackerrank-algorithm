#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int n, map[21][21], cnt=0;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}; 
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

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
  freopen("input.txt", "rt", stdin);
  cin >> n;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cin >> map[i][j];
    }
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      if(map[i][j] == 1) {
        Q.push(Loc(i, j));
        map[i][j] = 0;
        while(!Q.empty()) {
          Loc tmp = Q.front();
          Q.pop();
          for(int k=0; k<8; k++) {
            int xx = tmp.x+dx[k];
            int yy = tmp.y+dy[k];
            if(map[xx][yy] == 1) {
              Q.push(Loc(xx, yy));
              map[xx][yy] = 0;
            }
          }
        }
        cnt++;
      }
    }
  }

  cout << cnt;
	return 0;
}
