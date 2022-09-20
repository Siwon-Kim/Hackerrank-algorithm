#include <algorithm>
#include <iostream>

using namespace std;

int unf[1001]; // union and find ds using tree structure

int Find(int v) {
  if(v==unf[v]) return v;
  else return unf[v] = Find(unf[v]); // compression
}

void Union(int a, int b) {
  a = Find(a);
  b = Find(b);
  if(a!=b) unf[a] = b;
}


int main() {
	freopen("input.txt", "rt", stdin);
  int n, m, a, b, fa, fb;
  cin >> n >> m;
  for(int i=1; i<=n; i++) {
    unf[i] = i;
  }
  for(int i=1; i<=m; i++) {
    cin >> a >> b;
    Union(a, b);
  }
  cin >> a >> b;
  fa = Find(a);
  fb = Find(b);
  if(fa==fb) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}
