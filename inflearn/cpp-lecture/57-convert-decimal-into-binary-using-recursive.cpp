#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

void recur(int n) {
  if(n == 0) return;
  else recur(n/2);
  cout << n % 2;
}

int main() {
  freopen("input.txt", "rt", stdin);
  int n;
  cin >> n;
  recur(n);
  return 0;
}
