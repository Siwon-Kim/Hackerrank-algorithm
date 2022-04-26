#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int matrix[21][21];

int main() {
  // freopen("input.txt", "rt", stdin);
  cin >> n >> m;
  for(int i=1; i<=m; i++) {
    for(int j=1; j<=3; j++) {
      int start, end, dist;
      cin >> start >> end >> dist;
      matrix[start][end] = dist;
    }
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
  
  return 0;
}
