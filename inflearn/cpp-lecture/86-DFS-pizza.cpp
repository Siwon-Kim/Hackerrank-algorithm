#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int m, visited[20], dis, res=2147000000, sum=0;
vector<pair<int, int>> home;
vector<pair<int, int>> pizza;

void DFS(int L, int s) {
  if(L==m) {
    sum=0;
    for(int i=0; i<home.size(); i++) {
      int x1=home[i].first;
      int y1=home[i].second;
      dis=2147000000;
      for(int j=0; j<m; j++) {
        int x2=pizza[visited[j]].first;
        int y2=pizza[visited[j]].second;
        dis=min(dis, abs(x1-x2)+abs(y1-y2));
      }
      sum+=dis;
    }
    if(sum<res) res=sum;
  } else {
    for(int i=s; i<pizza.size(); i++) { // combination
      visited[L] = i;
      DFS(L+1, i+1);
    }
  }
}

int main() {
  freopen("input.txt", "rt", stdin);
  int n, a;
  cin >> n >> m;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cin >> a;
      if(a==1) home.push_back(make_pair(i, j));
      else if(a==2) pizza.push_back(make_pair(i, j));
    }
  }
  DFS(0, 0);
  cout << res;
	return 0;
}
