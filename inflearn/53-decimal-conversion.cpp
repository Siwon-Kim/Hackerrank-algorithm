#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  freopen("input.txt", "rt", stdin);
  int n, k, val;
  char str[20]="0123456789ABCDEF";
  cin >> n >> k;
  vector<int> s;
  while(n > 0) {
    val = n % k;
    n = n / k;
    s.push_back(val);
  }

  while(!s.empty()) {
    int output = s.back();
    cout << str[output];
    s.pop_back();
  }
  
  return 0;
}
