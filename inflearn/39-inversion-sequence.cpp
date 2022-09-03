#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
  //freopen("input.txt", "rt", stdin);
  int n;
  cin >> n;
  int in[n], out[n];
  for(int i=0; i<n; i++) {
    cin >> in[i];
    out[i] = 0;
  }
  
  for(int i=0; i<n; i++) {
    
    int cnt=0;
    for(int j=0; j<n; j++) {
      if(cnt == in[i]) {
        for(int k=j; k<n; k++) {
          if(out[k] == 0) {
            out[k] = i+1;
            break;
          }
        }
      }
      if(cnt == in[i]) break;
      if(out[j] == 0) {
        cnt++;
      }
    }
  }
  
  for(int i=0; i<n; i++) cout << out[i] << " ";
    
  return 0;
}

// using insertion sort
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
int main() {
  freopen("input.txt", "rt", stdin);
  int n;
  cin >> n;
  vector<int> in(n+1), out(n+1);
  for(int i=1; i<=n; i++) scanf("%d", &in[i]);

  for(int i=n; i>=1; i--) {
    int pos = i;
    for(int j=1; j<=in[i]; j++) {
      out[pos] = out[pos+1];
      pos++;
    }
    out[pos] = i;
  }
  
  for(int i=1; i<=n; i++) printf("%d ", out[i]);
    
  return 0;
}
