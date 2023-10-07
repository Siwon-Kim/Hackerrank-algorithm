#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
  int n;
  priority_queue<int> maxPQ;
  while(1) {
    cin >> n;
    if(n==-1) break;
    if(n==0) {
      if(maxPQ.empty()) cout << "-1" << "\n";
      else {
        cout << -maxPQ.top() << "\n";
        maxPQ.pop();
      }
    }
    else maxPQ.push(-n); 
  }
  
	return 0;
}
