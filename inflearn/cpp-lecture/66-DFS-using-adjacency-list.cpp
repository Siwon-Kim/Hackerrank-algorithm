#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> map[21];
int visited[21];
int n, cnt=0;

void DFS(int x) {
  if(x==n) cnt++;
  else {
    for(int i=0; i<map[x].size(); i++) {
      if(visited[map[x][i]]==0) {
        visited[map[x][i]] = 1;
        DFS(map[x][i]);
        visited[map[x][i]] = 0;
      }
    }
  }
}

int main() {
	freopen("input.txt", "rt", stdin);
  int m, n1, n2;
  cin >> n >> m;
	for(int i=1; i<=m; i++) {
    cin >> n1 >> n2;
    map[n1].push_back(n2);
  }
  visited[1] = 1;
  DFS(1);
   
  cout << cnt;

	return 0;
}
