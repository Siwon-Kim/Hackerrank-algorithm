#include<iostream>
#include<stack>
#include<map>

using namespace std;

// The posts
stack<int> A;
stack<int> B;
stack<int> C;

// To reference the stack name
map<stack<int> *, string> names;

// Count pushes and pops
int countPush = 0;
int countPop = 0;

// Function prototypes
void outputMove(int diskNum, string stackFrom, string stackTo);
void stacksOfHanoi(int n, stack<int>& stackFrom, stack<int>& stackTo, stack<int>& stackAux);


int main() {
 names[&A] = "A";
 names[&B] = "B";
 names[&C] = "C";

 // Number of disks (n is disk size)
 int n = 4;

 // Push disks from largest to smallest
 for (int i = n; i >= 1; i--) {
   A.push(i);
 }

 // Do the work
 stacksOfHanoi(n, A, C, B);

 // Print stack C from top down
 while (!C.empty()) {
   cout << C.top() << " ";
   C.pop();
 }
 cout << endl;

 cout << "Push Ops: " << countPush << endl;
 cout << "Pop Ops: " << countPop << endl;

 return 0;
}

void outputMove(int diskNum, string stackFrom, string stackTo) {
 cout << "Moving disk " << diskNum << " from post " << stackFrom << " to " << stackTo << endl;
}

void stacksOfHanoi(int n, stack<int>& stackFrom, stack<int>& stackTo, stack<int>& stackAux) {
 if (n == 1) {
   cout << "--base--" << endl;
   outputMove(stackFrom.top(), names[&stackFrom], names[&stackTo]);
   stackTo.push(stackFrom.top()); countPush++;
   stackFrom.pop(); countPop++;
 } else {
   cout << "--recursive--" << endl;
   stacksOfHanoi(n - 1, stackFrom, stackAux, stackTo);

   outputMove(stackFrom.top(), names[&stackFrom], names[&stackTo]);
   stackTo.push(stackFrom.top()); countPush++;
   stackFrom.pop(); countPop++;

   stacksOfHanoi(n - 1, stackAux, stackTo, stackFrom);
 }
}