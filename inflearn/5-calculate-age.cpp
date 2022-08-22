#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  freopen("input.txt", "rt", stdin);
  int age, year;
  char ssn[15];
  scanf("%s", ssn);
  if(ssn[7]=='1' || ssn[7]=='2') year=1900+((ssn[0]-48)*10+(ssn[1]-48));
	else year=2000+((ssn[0]-48)*10+(ssn[1]-48));
	age=2019-year+1;
	printf("%d ", age);
	if(ssn[7]=='1' || ssn[7]=='3') printf("M\n");
	else printf("W\n");
	return 0;
}
