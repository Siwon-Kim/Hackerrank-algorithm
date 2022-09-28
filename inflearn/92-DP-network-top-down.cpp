// Dynamic Programming
// Top-down: recursive function
// Utilizing memoization

#include <iostream>

using namespace std;

int dy[50]; // memoization

int DFS(int L) {
  if(dy[L]>0) return dy[L]; // using memoization
  if(L==1 || L==2) return L;
  else return dy[L] = DFS(L-1) + DFS(L-2);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  freopen("input.txt", "rt", stdin);
  int n;
  cin >> n;
  dy[1] = 1;
  dy[2] = 2;
  
  DFS(n);
  
  cout << dy[n];

  return 0;
}
