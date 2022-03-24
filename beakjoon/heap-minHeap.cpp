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
    int node = 1, lastIdx = heap.size() - 1;
    // print root
    cout << heap[node] << endl;
    // move the last node to the root node
    heap[node] = heap[lastIdx];
    // erase the last node
    heap.erase(heap.begin() + lastIdx);
     
    // pop root
    while(true) {
      int left = node * 2, right = node * 2 + 1;
      // break condition: when the root is already smallest 
      if(heap[node] <= heap[left]) break;
      
      int minV = heap[left], minPos = left;
      // when the right-value is bigger
      if(heap[left] > heap[right]){
        minV = heap[right];
        minPos = right;
      }
      
      if(heap[minPos] < heap[node]){
        swap(heap[minPos], heap[node]);
        node = minPos;
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
  heap.push_back(x);
  int node = heap.size() - 1, parent = node / 2;
   
  while(true){
      if(heap.size() == 1) break;
      
      if(heap[node] < heap[parent]) {
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
