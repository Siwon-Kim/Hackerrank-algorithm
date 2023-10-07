// before using memorization
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int combination(int n, int r) {
  if(n==r | r==0) return 1;
  else return combination(n-1, r-1) + combination(n-1, r);
}

int main() {
	freopen("input.txt", "rt", stdin);
  int n, r;
  cin >> n >> r;
  cout << combination(n, r);
}

// using memorization
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int mem[21][21];

int combination(int n, int r) {
  if(mem[n][r]>0) return mem[n][r];
  if(n==r | r==0) return 1;
  else return mem[n][r] = combination(n-1, r-1) + combination(n-1, r);
}

int main() {
	freopen("input.txt", "rt", stdin);
  int n, r;
  cin >> n >> r;
  cout << combination(n, r);
}
