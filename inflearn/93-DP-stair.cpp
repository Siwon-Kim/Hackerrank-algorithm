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
  for(int i=3; i<=n+1; i++) { // bottom-up
		dy[i]=dy[i-1]+dy[i-2];
	}
  
  cout << dy[n];

  return 0;
}
