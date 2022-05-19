#include <iostream>

using namespace std;

int n;

void print(int num) {
  if(num <= n) {
    cout << num++ << " ";
    print(num);
  }
}

int main() {
  cin >> n;
  print(1);
}

//-------------------- ans -----------------------//

#include <iostream>

using namespace std;

void recur(int n) {
  if(n == 0) return;
  else {
    recur(n-1);
    cout << n << " ";
  }
}

int main() {
  int n;
  cin >> n;
  recur(n);
  
  return 0;
}
