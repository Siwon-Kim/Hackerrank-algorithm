#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int ch[10], dis[10];

int main() {
	freopen("input.txt", "rt", stdin);
  int n, m, a, b, x;
  vector<int> map[10];
  queue<int> Q;  
  cin >> n >> m;
  for(int i=1; i<=m; i++) {
    cin >> a >> b;
    map[a].push_back(b);
  }
  ch[1] = 1;
  Q.push(1);

  while(!Q.empty()) {
    x = Q.front();
    Q.pop();
    for(int i=0; i<map[x].size(); i++) {
      if(ch[map[x][i]]==0) {
        ch[map[x][i]] = 1;
        Q.push(map[x][i]);
        dis[map[x][i]] = dis[x]+1;
      }
    }
  }

  for(int i=2; i<=n; i++) {
    cout << i << " : " << dis[i] << "\n";
  }
 
	return 0;
}
