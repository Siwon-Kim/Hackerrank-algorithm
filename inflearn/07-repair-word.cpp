#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
  freopen("input.txt", "rt", stdin);
  char word[101], newWord[101];
	int p=0;
	scanf("%[^\n]", word);

  for(int i=0; word[i]!='\0'; i++) {
    if(word[i] != ' ') {
      if(word[i]>=65 && word[i]<=90) {
				newWord[p++] = word[i] + 32;
			}
			else newWord[p++] = word[i];
    }
  }
  newWord[p] = '\0';
  printf("%s\n", newWord);
  return 0;
}
