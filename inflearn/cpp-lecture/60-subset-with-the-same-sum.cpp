#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, ch[40], total=0;
bool flag = false;

void DFS(int L, int sum) {
  if(sum>(total/2)) return;
  if(L==n+1) {
    if(sum==(total-sum)) {
      flag = true;
    }
  } else {
    DFS(L+1, sum+ch[L]);
    DFS(L+1, sum);
  }
}

int main() {
  freopen("input.txt", "rt", stdin);
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> ch[i];
    total += ch[i];
  }
  DFS(1, 0);
  if(flag) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}
