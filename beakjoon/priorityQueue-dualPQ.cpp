#include <iostream>
#include <vector>

using namespace std;

int T;
int k;

struct doubleEndedQueue {
  vector<int> Q;

  bool isEmpty() {
    return Q.size() == 1;
  }

  int getMin() {
    return *(Q.begin() + 1);
  }

   int getMax() {
    int lastIdx = Q.size() - 1;
    return Q[lastIdx];
  }

  void push(int x) {
    Q.push_back(x);
    int node = Q.size() - 1, parent = node / 2;
   
    while(true) {
      if(Q.size() == 1) break;
      if(parent == 0) break;
      if(Q[node] < Q[parent]) {
        swap(Q[parent], Q[node]);
        node /= 2;
        parent = node/2;
      } else {
         break;
      }
    }
  }

  void popMax() {
    if(Q.size() > 1) {
      int lastIdx = Q.size() - 1;
      Q.erase(Q.begin() + lastIdx);
    } else {
      return;
    }
  }

  void popMin() {
    if(Q.size() > 1) {
      int node = 1, lastIdx = Q.size() - 1;
      Q[node] = Q[lastIdx];
      Q.erase(Q.begin() + lastIdx);
       
      while(true) {
        int left = node * 2, right = node * 2 + 1;
        if(Q[node] <= Q[left]) break;
        
        int minV = Q[left], minPos = left;
        if(Q[left] > Q[right]){
          minV = Q[right];
          minPos = right;
        }
        
        if(Q[minPos] < Q[node]){
          swap(Q[minPos], Q[node]);
          node = minPos;
        } else {
          break;
        }
      }
    } else {
      return;
    }
  }
};

int main() {
  doubleEndedQueue Q;
  Q.push(0);
  cin >> T;
  for(int i=0; i<T; i++) {
    cin >> k;
    // 문제: Q를 비워줘야 됌
    for(int j=0; j<k; j++) {
      char opr; // D for push or I for pop
      int num;
      cin >> opr;
      if(opr == 'I') {
        cin >> num;
        Q.push(num);
      } else { // opr == 'D'
        cin >> num;
        if(num == 1) Q.popMax();
        else Q.popMin();
      } 
    }
    if(Q.isEmpty() == 1) cout << "EMPTY" << endl;
    else cout << Q.getMax() << " " << Q.getMin() << endl;
  }
  
  return 0;
}
