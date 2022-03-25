#include <cstdio>
#include <queue>
#include <iostream>  
#include <functional>
#include <vector>

using namespace std;

int n;
vector<long> heap;

void pop() {
  if(heap.size() > 1) {
    // print root
    printf("%d\n", heap[1]);
    int node = 1, lastIdx = heap.size() - 1;
    // move the last node to the root node
    heap[node] = heap[lastIdx];
    // erase the last node
    heap.erase(heap.begin() + lastIdx);
     
    // pop root
    while(true) {
      int left = node * 2, right = node * 2 + 1;
      // break condition
      if(left >= lastIdx) break;
      
      int maxV = heap[left], maxPos = left;
      // when the right-value is bigger (high priority)
      if(right<lastIdx && maxV < heap[right]){
        maxV = heap[right];
        maxPos = right;
      }
      
      if(heap[maxPos] > heap[node]){
        swap(heap[maxPos], heap[node]);
        node = maxPos;
      } else {
        break;
      }
    }
  } else { // heap size = 0
      printf("0\n");
  }
}

void push(int x){
  // push x end of heap
  heap.push_back(x);;
  int node = heap.size() - 1, parent = node / 2;
  
  while(true){
      if(parent == 0) break;
      
      if(heap[node] > heap[parent]) {
        // swap
        swap(heap[parent], heap[node]);
        // update index
        node /= 2;
        parent = node/2;
      } else {
         break;
      }
   }
}

int main(){
	scanf("%d", &n);
	heap.push_back(0);
	
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		
		if(x == 0){	
			pop();
		} else {
			push(x);
		}
	}
	
	return 0;
}
