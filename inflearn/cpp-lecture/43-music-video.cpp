#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a;
int n;

int count(int num) {
  int cnt=1, sum=0;
  for(int i=0; i<n; i++) {
    if(sum + a[i] > num) {
      cnt++;
      sum = a[i];
    } else sum += a[i];
  }
  return cnt;
}

int main() {
  freopen("input.txt", "rt", stdin);
  
  int m, tmp, ans, mid, lt=1, rt=0, max=-2147000000;
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    cin >> tmp;
    a.push_back(tmp);
    rt += tmp;
    if(tmp>max) max=tmp;
  }

  while(lt<=rt) {
    mid = (lt+rt)/2;
    if(mid>=max && count(mid)<=m) {
      ans = mid;
      rt = mid-1;
    } else lt = mid+1;
  }
  cout << ans << "\n";
  return 0;
}
