#include <iostream>
#include <cstring>
using namespace std;

int n;
int d[101][101];
bool isVisited[101] = {false};

void DFS(int curr_node) {
  for(int i=0; i<n; i++) {
    if(d[curr_node][i] == 1 && !isVisited[i]) {
      isVisited[i] = true;
      DFS(i);
    }
  }
}

int main() {
  // input
  freopen("input.txt", "rt", stdin);
  cin >> n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> d[i][j];
    }
  }

  // code
  for(int i=0; i<n; i++) {
    memset(isVisited, false, sizeof(isVisited));
    DFS(i);
    for(int j=0; j<n; j++) {
      if(isVisited[j]) d[i][j] = 1;
    }
  }

  // print
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cout << d[i][j] << " ";
    }
    cout << "\n";
  }
}
