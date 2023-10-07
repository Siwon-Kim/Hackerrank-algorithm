#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int n, T[20], P[20], res=0;

void DFS(int L, int sum) {
  if(L==n+1) {
    if(sum>res) res=sum;
  } else {
    if(L+T[L]<=n+1) DFS(L+T[L], sum+P[L]);
    DFS(L+1, sum);
  }
}

int main() {
  freopen("input.txt", "rt", stdin);
  cin >> n;
  for(int i=1; i<=n; i++) {
    cin >> T[i] >> P[i];
  }
  DFS(1, 0);
  
  cout << res << "\n";
  
	return 0;
}
