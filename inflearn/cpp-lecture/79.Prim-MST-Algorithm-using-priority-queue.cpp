/* 
  Prim MST Algorithm
  :  Prim’s algorithm always starts with a single node and it moves through several adjacent nodes, 
     in order to explore all of the connected edges along the way.
     
     It starts with an empty spanning tree. 
     The idea is to maintain two sets of vertices. 
     The first set contains the vertices already included in the MST, 
     the other set contains the vertices not yet included. 
     At every step, it considers all the edges that connect the two sets and picks the minimum weight edge from these edges. 
     After picking the edge, it moves the other endpoint of the edge to the set containing MST. 
*/

#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int ch[30];

struct Edge {
	int e;
	int val;
	Edge(int a, int b) {
		e=a;
		val=b;
	}
	bool operator<(const Edge &b) const {
		return val>b.val; // descending
	}
};

int main() {
	freopen("input.txt", "rt", stdin);
  
	priority_queue<Edge> Q;
	vector<pair<int, int>> map[30];
	int i, v, e, a, b, c, res=0;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b, c));	
		map[b].push_back(make_pair(a, c));
	}
	Q.push(Edge(1, 0)); // starting with a single node
  
	while(!Q.empty()){
		Edge tmp=Q.top(); // selecting a single node
		Q.pop();
		int v=tmp.e;
		int cost=tmp.val;
		if(ch[v]==0){
			res+=cost;
			ch[v]=1;
			for(i=0; i<map[v].size(); i++){
				if(ch[map[v][i].first]==0){
					Q.push(Edge(map[v][i].first, map[v][i].second));
				}
			}
		}
		
	}
	printf("%d\n", res);
	return 0;
}
