#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int n, op[5], a[11], maxVal=-2147000000, minVal=2147000000;

void DFS(int L, int res) {
  if(L==n) {
    if(res>maxVal) maxVal=res;
    if(res<minVal) minVal=res;
  }
  else {
    if(op[1]>0) { // addition
      op[1]--;
      DFS(L+1, res+a[L+1]);
      op[1]++;
    }
    if(op[2]>0) { // subtraction
      op[2]--;
      DFS(L+1, res-a[L+1]);
      op[2]++;
    }
    if(op[3]>0) { // multiplication
      op[3]--;
      DFS(L+1, res*a[L+1]);
      op[3]++;
    }
    if(op[4]>0) { // division
      op[4]--;
      DFS(L+1, res/a[L+1]);
      op[4]++;
    }
  }
}

int main() {
  freopen("input.txt", "rt", stdin);
  cin >> n;
  for(int i=1; i<=n; i++) {
    cin >> a[i];
  }
  for(int i=1; i<=4; i++) {
    cin >> op[i];
  }
  DFS(1, a[1]);
  cout << maxVal << "\n" << minVal;
  
	return 0;
}
