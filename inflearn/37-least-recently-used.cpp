#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
  freopen("input.txt", "rt", stdin);
  int s, n, work;
  cin >> s >> n;
  int cache[s];
  for(int i=0; i<s; i++) cache[i] = 0;
  
  for(int i=0; i<n; i++) {
    int idx = -1;
    cin >> work;
    for(int j=0; j<s; j++) {
      if(cache[j] == work) idx = j;
    }
    if(idx == -1) {
        for(int k=s-2; k>=0; k--) cache[k+1] = cache[k];
      } else {
        for(int k=idx-1; k>=0; k--) cache[k+1] = cache[k];
      }
      cache[0] = work;
  }

  for(int i=0; i<s; i++) cout << cache[i] << " ";
    
  return 0;
}
