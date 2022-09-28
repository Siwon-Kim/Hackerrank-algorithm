// Dynamic Programming
// Bottom-up: using for loop
// Recurrence Relation: f(n)=f(n-2)+f(n-1)

#include <iostream>

using namespace std;

int dy[50];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  freopen("input.txt", "rt", stdin);
  int n;
  cin >> n;
  dy[1] = 1;
  dy[2] = 2;
  for(int i=3; i<=n; i++) {
    dy[i] = dy[i-2] + dy[i-1];
  }

  cout << dy[n];

  return 0;
}
