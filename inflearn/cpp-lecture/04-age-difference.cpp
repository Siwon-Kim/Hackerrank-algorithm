#include <iostream>

using namespace std;

int main() {
  freopen("input.txt", "rt", stdin);
  int n, age;
  int max=-2147000000, min=2147000000;
  cin >> n;
  for(int i=1; i<=n; i++) {
    cin >> age;
    if(age>=max) max=age;
    if(age<=min) min=age;
  }
  cout << max-min;
}
