/*
Kruskal MST Algorithm (Minial Spanning Tree)
: A Spanning tree is a subset to a connected graph G, where all the edges are connected, 
  i.e, one can traverse to any edge from a particular edge with or without intermediates. 
  Also, a spanning tree must not have any cycle in it. 
  Thus we can say that if there are N vertices in a connected graph 
  then the no. of edges that a spanning tree may have is N-1.
  
: Given a connected and undirected graph, 
  a spanning tree of that graph is a subgraph that is a tree and connects all the vertices together. 
  A single graph can have many different spanning trees. 
  A minimum spanning tree (MST) or minimum weight spanning tree for a weighted, connected, undirected graph 
  is a spanning tree with a weight less than or equal to the weight of every other spanning tree.
  The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.
  
  * How many edges does a minimum spanning tree has? 
    -> A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph. 
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int unf[1001];

struct Edge {
  int c1;
  int c2;
  int cost;
  Edge(int a, int b, int c) { // constructor: initializing the values
    c1 = a;
    c2 = b;
    cost = c;
  }
  bool operator<(const Edge &b) const {
    return cost < b.cost; // ascending
  }
};

int Find(int v) {
  if(v==unf[v]) return v;
  else return unf[v] = Find(unf[v]); // compression
}

void Union(int a, int b) {
  a = Find(a);
  b = Find(b);
  if(a!=b) unf[a] = b;
}

int main() {
	freopen("input.txt", "rt", stdin);
  vector<Edge> Ed; // tree
  int v, e, c1, c2, cost, minCost=0;
  cin >> v >> e; // v: vertix, e: edge
  for(int i=1; i<=v; i++) {
    unf[i] = i;
  }
  for(int i=1; i<=e; i++) {
    cin >> c1 >> c2 >> cost;
    Ed.push_back(Edge(c1, c2, cost));
  }
  sort(Ed.begin(), Ed.end());
  for(int i=0; i<e; i++) {
    int city1 = Find(Ed[i].c1);
    int city2 = Find(Ed[i].c2);
    if(city1!=city2) {
      minCost += Ed[i].cost;
      Union(Ed[i].c1, Ed[i].c2);
    }
  }

  cout << minCost;
  
  return 0;
}
