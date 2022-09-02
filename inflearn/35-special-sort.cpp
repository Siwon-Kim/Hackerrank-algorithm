#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
  freopen("input.txt", "rt", stdin);
  int n;
  cin >> n;
  int a[n];
  for(int i=0; i<n; i++) cin >> a[i];

  for(int i=0; i<n; i++) {
    for(int j=0; j<n-i-1; j++) {
      if(a[j] > 0 && a[j+1] < 0) {
        swap(a[j], a[j+1]);
      }
    }
  }

  for(int i=0; i<n; i++) cout << a[i] << " ";
  return 0;
}
