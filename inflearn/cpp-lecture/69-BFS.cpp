#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> map[10];
int ch[10], Q[10], front=-1, back=-1;

int main() {
	freopen("input.txt", "rt", stdin);
  int a, b, x;
  for(int i=1; i<=6; i++) {
    cin >> a >> b;
    map[a].push_back(b);
    map[b].push_back(a);
  }
  
  ch[1] = 1;
  Q[++back] = 1;

  while(front<back){
		x=Q[++front];
		cout << x << " ";
		for(int i=0; i<map[x].size(); i++){
			if(ch[map[x][i]]==0){
				ch[map[x][i]]=1;
				Q[++back]=map[x][i];
			}
		}
	}

	return 0;
