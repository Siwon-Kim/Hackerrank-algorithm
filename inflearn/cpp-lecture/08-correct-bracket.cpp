#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

int main() {
  freopen("input.txt", "rt", stdin);
  char bracket[31];
  stack<int> stack;
  scanf("%s", bracket);

  for(int i=0; bracket[i]!='\0'; i++) {
    if(bracket[i] == '(') {
      stack.push(0);
    } else {
      stack.pop();
    }
  }

  if(stack.empty()) {
    printf("YES");
  } else {
    printf("NO");
  }
  
  return 0;
}

// not using stack
#include<stdio.h>

using namespace std;

int main(){
	//freopen("input.txt", "rt", stdin);
	char a[100];
	int i, cnt=0;
	scanf("%s", &a);
	for(i=0; a[i]!='\0'; i++){
		if(a[i]=='(') cnt++;
		else if(a[i]==')') cnt--;
		if(cnt<0) break;
	}
	if(cnt==0) printf("YES\n");
	else printf("NO\n");
	return 0;
}
