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
