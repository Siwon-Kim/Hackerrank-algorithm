#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define MIN 2147000000

using namespace std;

int dist[21];

struct Edge {
  int s;
  int e;
  int val;
  Edge(int a, int b, int c) {
    s = a;
    e = b;
    val = c;
  }
}

int main() {
	freopen("input.txt", "rt", stdin);
  vector<Edge> Ed;
  int n, m, v1, v2, dis;
  cin >> n >> m;
  for(int i=1; i<=m; i++) {
    cin >> v1 >> v2 >> dis;
    Ed.push_back(Edge(v1, v2, dis));
  }
  for(int i=1; i<=n; i++) dist[i] = MIN;
  int s, e;
  cin >> s >> e;
  
  for(int i=1; i<n; i++) {
    for(int j=0; j<Ed.size(); j++) {
      int s = Ed[j].s;
      int e = Ed[j].e;
      int w = Ed[j].val;
      if(dist[s]!=MIN && dist[s]+w<dist[e])
        dist[e] = dist[s] + w;
    }
  }
  
  for(int i=0; i<Ed.size(); i++) {
    int u=Ed[i].s;
		int v=Ed[i].e;
		int w=Ed[i].val;
		if(dist[u]!=MIN && dist[u]+w<dist[v]){
			cout << -1;
			exit(0);
	}
    
	cout << dist[e];
    
  return 0;
}
