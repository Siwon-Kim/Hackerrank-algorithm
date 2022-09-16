#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<int, int>> map[21];
int visited[21];
int n, minCost=2147000000;

void DFS(int x, int sum) {
  if(x==n) {
    if(sum<minCost) minCost = sum;
  }
  else {
    for(int i=0; i<map[x].size(); i++) {
      if(visited[map[x][i].first]==0) {
        visited[map[x][i].first] = 1;
        DFS(map[x][i].first, sum+map[x][i].second);
        visited[map[x][i].first] = 0;
      }
    }
  }
}

int main() {
	freopen("input.txt", "rt", stdin);
  int m, n1, n2, dis;
  cin >> n >> m;
	for(int i=1; i<=m; i++) {
    cin >> n1 >> n2 >> dis;
    map[n1].push_back(make_pair(n2, dis));
  }
  visited[1] = 1;
  DFS(1, 0);
   
  cout << minCost;

	return 0;
}
