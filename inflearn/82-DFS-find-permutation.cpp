#include <queue>

using namespace std;

int n, r, cnt=0;
int vertices[20], res[20], visited[20];

void DFS(int L) {
  if(L==r) {
    for(int i=0; i<L; i++) {
      cout << res[i] << " ";
    }
    cnt++;
    cout << "\n";
  } else {
    for(int i=1; i<=n; i++) {
      if(visited[i]==0) {
        res[L] = vertices[i];
        visited[i] = 1;
        DFS(L+1);
        visited[i] = 0;
      }
    }
  }
}

int main() {
	freopen("input.txt", "rt", stdin);
  cin >> n >> r;
  for(int i=1; i<=n; i++) cin >> vertices[i];

  DFS(0);
  cout << cnt;
  
  return 0;
}
