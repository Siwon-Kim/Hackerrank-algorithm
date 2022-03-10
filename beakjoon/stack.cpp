// stack #10828
// error
#include <iostream>

using namespace std;

class Stack {
  public: 
    int size() const;
    bool empty() const;
    int top() const;
    void push(int e);
    int pop();
  private:
    int capacity = 100;
    int S[capacity];
    int index = -1;
};

int Stack::size() const {
  return index + 1;
}

bool Stack::empty() const {
  return index < 0;
}

int Stack::top() const {
  if(empty()) return -1;
  else {
    return S[index];
  }
}

void Stack::push(int e) {
  S[++index] = e;
}

int Stack::pop() {
  if(empty()) return -1;
  else {
    int val = S[index];
    --index;
    return val;
  }
}

int main() {
  Stack S;
  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    string s;
    cin >> s;
    if (s == "push") {
      int input;
      cin >> input;
      S.push(input);
    } else if(s == "pop") {
      cout << S.pop() << endl;
    } else if(s == "top") {
      cout << S.top() << endl;
    } else if(s == "size") {
      cout << S.size() << endl;
    } else if(s == "empty") {
      cout << S.empty() << endl;
    } else {
      cout << "enter the correct command";
    }  
  }
  return 0;
}
