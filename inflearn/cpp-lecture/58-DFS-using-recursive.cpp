#include <stdio.h>
#include <iostream>

using namespace std;

void DFS(int k, int n) {
  if(k > n) return;
  else  {
    cout << k << " "; // pre-order
    DFS(k*2, n);
    cout << k << " "; // in-order
    DFS(k*2+1, n);
    cout << k << " "; // post-order
  }
}

int main() {
  int n;
  cin >> n;
  DFS(1, n);
  return 0;
}
