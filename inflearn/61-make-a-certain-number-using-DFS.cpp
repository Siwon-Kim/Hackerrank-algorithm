#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, ch[11], cnt=0;

void DFS(int L, int cal) {
  if(L==n+1) {
    if(cal==m) {
      cnt++;
    }
  } else {
    DFS(L+1, cal+ch[L]);
    DFS(L+1, cal);
    DFS(L+1, cal-ch[L]);
  }
}

int main() {
  freopen("input.txt", "rt", stdin);
  cin >> n >> m;
  for(int i=1; i<=n; i++) {
    cin >> ch[i];
  }
  DFS(1, 0);
  if(cnt==0) cout << -1;
  else cout << cnt;
  return 0;
}
