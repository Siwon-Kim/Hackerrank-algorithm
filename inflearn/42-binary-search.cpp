#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  freopen("input.txt", "rt", stdin);
  int n, m, lt, rt, mid;
  cin >> n >> m;
  vector<int> a(n);
  for(int i=0; i<n; i++) scanf("%d ", &a[i]);

  sort(a.begin(), a.end());
  
  lt = 0; 
  rt = n-1; 

  for(int i=0; i<n; i++) {
    mid = (lt+rt)/2;

    if(a[mid] == m) {
      cout << mid+1 << "\n";
      break;
    } else if(a[mid] > m) {
      rt = mid - 1;
    } else if(a[mid] < m) {
      lt = mid + 1;
    }
  }
  
  return 0;
}
