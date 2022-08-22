#include <iostream>

using namespace std;

int main() {
  int n;
  int sum=1;
  cin >> n;
  
  cout << 1;
  for(int i=2; i<=n; i++) {
    if(n%i == 0) {
      if(i==n) cout << " = " << sum;
      else {
        sum += i;
        cout << " + " << i;
      }
    }
  }
}
