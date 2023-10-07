#include <iostream>

using namespace std;

int main() {
  int n, m;
  int sum=0;
  cin >> n >> m;

  for(int i=n; i<=m; i++) {
    sum += i;
    if(i == m) {
      cout << i << " = " << sum;
    } else 
    cout << i << " + ";
  }
}
