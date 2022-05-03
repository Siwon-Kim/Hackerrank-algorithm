// 59. 부분집합 구하기

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, ch[100];

void DFS(int L) {
  if(L==n+1) {
    for(int i=1; i<=n; i++) {
      if(ch[i]==1) cout << i << " ";
    }
    cout << "\n";
  } else {
    ch[L] = 1;
    DFS(L+1);
    ch[L] = 0;
    DFS(L+1);
  }
}

int main() {
  cin >> n;
  DFS(1);
  return 0;
}
