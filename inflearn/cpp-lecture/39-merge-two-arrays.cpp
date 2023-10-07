#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
int main() {
  freopen("input.txt", "rt", stdin);
  int n, m, a[201], j ;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  cin >> m;
  for(int i=0; i<m; i++) {
    cin >> a[i+n];
  }
  int size = n+m;
  
  for(int i=0; i<size; i++) {
    int tmp = a[i];
    for(j=i-1; j>=0; j--) {
      if(tmp < a[j]) {
        a[j+1] = a[j];
      }
      else break;
    }
    a[j+1] = tmp;
  }

  for(int i=0; i<size; i++) cout << a[i] << " ";
  
  return 0;
}

// using three pointers
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int a[101], b[101], c[300];
int main(){
	freopen("input.txt", "rt", stdin);
	int n, m, i, p1=1, p2=1, p3=1;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for(i=1; i<=m; i++){
		scanf("%d", &b[i]);
	}
	while(p1<=n && p2<=m){
		if(a[p1]<b[p2]){
			c[p3++]=a[p1++];
		}
		else{
			c[p3++]=b[p2++];
		}
	}
	while(p1<=n) c[p3++]=a[p1++];
	while(p2<=m) c[p3++]=b[p2++];
	for(i=1; i<p3; i++){
		printf("%d ", c[i]);
	}
	return 0;
}
