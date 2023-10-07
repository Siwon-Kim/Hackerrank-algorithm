#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  freopen("input.txt", "rt", stdin);
  int n, k, p=0, term=0, cnt=0;
  cin >> n >> k;
  vector<int> prince(n+1);
  // A vector, once declared, has all its values initialized to zero.
  while(1) {
    p++;
    if(p>n) p=1; // when reached to the end of vector
    if(prince[p]==0) {
      cnt++;
      if(cnt==k) {
        prince[p] = 1; // selected mark
        cnt = 0;
        term++;
      }
    }
    if(term==n-1) break;
  }
  
  for(int i=1; i<=n; i++) {
    if(prince[i] == 0) {
      cout <<  i << "\n";
      break;
    }
  }
  
  return 0;
}
