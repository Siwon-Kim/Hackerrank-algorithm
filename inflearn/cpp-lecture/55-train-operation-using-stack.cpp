#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main() {
  freopen("input.txt", "rt", stdin);
  int n, m, j=1;
  stack<int> s;
  vector<char> str;
  cin >> n;

  for(int i=1; i<=n; i++) {
    cin >> m;
    s.push(m);
    str.push_back('P');
    while(1) {
      if(s.empty()) break;
      if(j==s.top()) {
        s.pop();
        str.push_back('O');
        j++;
      } else break;
    }
  }

  if(!s.empty()) cout << "impossible\n";
  else {
    for(int i=0; i<str.size(); i++) cout << str[i];
  }
  
  return 0;
}
