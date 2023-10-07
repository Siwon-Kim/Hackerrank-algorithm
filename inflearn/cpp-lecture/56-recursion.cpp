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

// Recursion based on stack
#include <iostream>

using namespace std;

void recur(int x) {
  if(x == 0) return;
  else {
    recur(x-1);
    cout << x << " ";
  }
}

int main() {
  int n;
  cin >> n;
  recur(n);
  
  return 0;
}
