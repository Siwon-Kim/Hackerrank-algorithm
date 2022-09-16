#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int map[21][21];
int visited[21];
int n, minCost=2147000000;

void DFS(int x, int sum) {
  if(x==n) {
    if(sum<minCost) minCost = sum;
  }
  else {
    for(int i=1; i<=n; i++) {
      if(map[x][i]>0 && visited[i]==0) {
        visited[i] = 1;
        DFS(i, sum+map[x][i]);
        visited[i] = 0;
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
    map[n1][n2] = dis;
  }
  visited[1] = 1;
  DFS(1, 0);
   
  cout << minCost;

	return 0;
}
