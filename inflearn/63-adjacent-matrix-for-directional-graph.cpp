#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int map[21][21];

int main() {
	freopen("input.txt", "rt", stdin);
	int n, m, from, to, dis;
  cin >> n >> m;
  for(int i=1; i<=m; i++) {
    cin >> from  >> to >> dis;
    map[from][to] = dis;
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cout << map[i][j] << " ";
    }
    cout << "\n";
  }

	return 0;
}
