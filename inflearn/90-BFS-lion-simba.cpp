#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int plain[26][26], ch[26][26];

struct Loc{
	int x;
	int y;
  int dis;
	Loc(int a, int b, int c) {
		x = a;
		y = b;
    dis = c;
	}
  bool operator<(const Loc &b) const {
    if(dis!=b.dis) return dis>b.dis;
    if(x!=b.x) return x>b.x;
    else return y>b.y;
  }
};

struct Lion {
  int x;
  int y;
  int size;
  int ate;
  void sizeUp() {
    ate=0;
    size++;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  freopen("input.txt", "rt", stdin);
  int n, res=0;
  Lion simba;
  priority_queue<Loc> PQ;
  cin >> n;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cin >> plain[i][j];
      if(plain[i][j]==9) {
        simba.x=i;
        simba.y=j;
        plain[i][j]=0;
      }
    }
  }
  PQ.push(Loc(simba.x, simba.y, 0));
  simba.size=2;
  simba.ate=0;
  while(!PQ.empty()) {
    Loc tmp = PQ.top();
    PQ.pop();
    int x=tmp.x;
    int y=tmp.y;
    int dis=tmp.dis;
    if(plain[x][y]!=0 && plain[x][y]<simba.size) { // when rabbit will be eaten
      simba.x=x;
      simba.y=y;
      simba.ate++;
      if(simba.ate>=simba.size) simba.sizeUp(); // when simba ate the number of rabbits as its size
      plain[x][y]=0;
      for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
          ch[i][j]=0; // reset check
        }
      }
      while(!PQ.empty()) PQ.pop(); // reset PQ
      res=tmp.dis; 
    }
    for(int i=0; i<4; i++) {
      int xx=x+dx[i];
      int yy=y+dy[i];
      if(xx<1 || xx>n || yy<1 || yy>n || plain[xx][yy]>simba.size || ch[xx][yy]>0) continue;
			PQ.push(Loc(xx, yy, dis+1));
			ch[xx][yy]=1;
    }
  }
  cout << res;
  
	return 0;
}
