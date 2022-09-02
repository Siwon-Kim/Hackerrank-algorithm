#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
  // freopen("input.txt", "rt", stdin);
  int n;
  cin >> n;
  int score[n];
  for(int i=0; i<n; i++) cin >> score[i];

  for(int i=0; i<n; i++) {
    int max = i;
    for(int j=i+1; j<n; j++) {
      if(score[max] < score[j]) 
        max = j;
    }
    swap(score[max], score[i]);
  }

  int cnt = 0;
  for(int i=1; i<n; i++) {
    if(score[i-1] != score[i]) {
      cnt++;
      if(cnt == 3) cout << score[i-1];
    }
  }
  return 0;
}
