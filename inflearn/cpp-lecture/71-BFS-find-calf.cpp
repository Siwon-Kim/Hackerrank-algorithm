#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int ch[10001], d[3]={1, -1, 5};

int main() {
	freopen("input.txt", "rt", stdin);
  int s, e, x, cnt=0, pos;
  vector<int> map[10];
  queue<int> Q;  
  cin >> s >> e;

  ch[s] = 1;
  Q.push(s);
  
  while(!Q.empty()) {
    x = Q.front();
    Q.pop();
    for(int i=0; i<3; i++) {
      pos=x+d[i];
      if(pos<=0 || pos>10000) continue;
      if(pos==e) {
        cout << ch[x];
        exit(0);
      }
      if(ch[pos]==0) {
        Q.push(pos);
        ch[pos]=ch[x]+1;
      }
    }
  }
 
	return 0;
}
