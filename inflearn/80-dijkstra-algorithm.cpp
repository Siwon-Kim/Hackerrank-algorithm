#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define MIN 2147000000

using namespace std;

vector<pair<int, int>> map[21];
int visited[21], dist[21];

int main() {
	freopen("input.txt", "rt", stdin);
  int n, m, v1, v2, dis, min;
  cin >> n >> m;
  for(int i=1; i<=m; i++) {
    cin >> v1 >> v2 >> dis;
    map[v1].push_back(make_pair(v2, dis));
  }
  for(int i=0; i<=n; i++) dist[i] = MIN;
  dist[1] = 0;
  for(int i=1; i<=n; i++) {
    min=0;
    for(int j=1; j<=n; j++) {
      if(visited[j]==0 && dist[j]<dist[min]) 
        min=j;
    }
    visited[min]=1;
    for(int j=0; j<map[min].size(); j++) {
      int v = map[min][j].first;
      int cost = map[min][j].second;
      if(dist[v]>dist[min]+cost) 
        dist[v] = dist[min] + cost;
    }
  }
  for(int i=2; i<=n; i++) {
    if(dist[i]!=MIN) cout << i << " : " << dist[i] << "\n";
    else cout << i << " : impossible\n";
  }
  
  return 0;
}
