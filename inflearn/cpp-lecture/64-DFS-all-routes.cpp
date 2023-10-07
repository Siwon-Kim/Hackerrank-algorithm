#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int map[21][21], check[21];
int n, cnt = 0;

void DFS(int L) {
  if(L==n) cnt++;
  for(int i=1; i<=n; i++) {
    if(map[L][i]==1 && check[i]==0) {
      check[i] = 1;
      DFS(i);
      check[i] = 0;
    }
  }
}

int main() {
	freopen("input.txt", "rt", stdin);
	int m;
  cin >> n >> m;
  for(int i=1; i<=m; i++) {
    int n1, n2;
    cin >> n1 >> n2;
    map[n1][n2] = 1;
  }
  check[1] = 1;
  DFS(1);
   
  cout << cnt;

	return 0;
}
