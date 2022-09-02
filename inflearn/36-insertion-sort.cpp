#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
  freopen("input.txt", "rt", stdin);
  int n, i, j;
  cin >> n;
  int a[n];
  for(int i=0; i<n; i++) cin >> a[i];

  for(i=1; i<n; i++) {
    int tmp = a[i];
    for(j=i-1; j>=0; j--) {
      if(a[j] > tmp) a[j+1] = a[j];
      else break;
    }
    a[j+1] = tmp;
  }

  for(int i=0; i<n; i++) cout << a[i] << " ";
  return 0;
}
