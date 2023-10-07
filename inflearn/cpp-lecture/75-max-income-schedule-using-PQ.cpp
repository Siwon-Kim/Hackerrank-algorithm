#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Lecture {
  int money;
  int day;
  Lecture(int a, int b) {
    money = a;
    day = b;
  }
  bool operator<(const Lecture &c) const {
    return day>c.day; // descending order
  }
};

int main() {
	freopen("input.txt", "rt", stdin);
  int n, m, d, total=0, maxDay=-2147000000;
  priority_queue<int> PQ;
  vector<Lecture> L;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> m >> d;
    L.push_back(Lecture(m, d));
    if(d>maxDay) maxDay = d;
  }
  sort(L.begin(), L.end());
  int j=0;
  for(int i=maxDay; i>=1; i--) {
    for( ; j<n; j++) {
      if(L[j].day<i) break;
      PQ.push(L[j].money);
    }
    if(!PQ.empty()) {
      total += PQ.top();
      PQ.pop();
    }
  }
  cout << total;
	return 0;
}
