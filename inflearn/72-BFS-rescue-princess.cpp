#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int ch[1001];
// 494
int main() {
	freopen("input.txt", "rt", stdin);
  int n, k, x, cnt=1;
  cin >> n >> k;
  queue<int> Q;
  for(int i=1; i<=n; i++) Q.push(i);
  
  while(Q.size()!=1) {
    x=Q.front();
    if(cnt==k) {
      Q.pop();
      cnt=1;  
    }
    else {
      cnt++;
      Q.pop();
      Q.push(x);
    }
  }

  cout << Q.front();
  Q.pop();
 
	return 0;
}
