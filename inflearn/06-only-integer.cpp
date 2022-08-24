#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
  freopen("input.txt", "rt", stdin);
  char input[50];
  int res = 0, cnt = 0;
  scanf("%s", &input);
  
  for(int i=0; input[i] != '\0'; i++) {
    if(input[i] >= 48 && input[i] <= 57){
			res = res * 10 + (input[i] - 48);
		}
  }
  printf("%d\n", res);
  for(int i=1; i<=res; i++) {
    if(res % i == 0) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
}
