#include <iostream>

using namespace std;

int data[10], tmp[10];

void divide(int left, int right) {
	int mid;
	int p1, p2, p3;
	if(left < right) {
		mid = (left + right) / 2;
		divide(left, mid);
		divide(mid+1, right);
		p1 = left;
		p2 = mid + 1;
		p3 = left;
		while(p1 <= mid && p2 <= right) {
			if(data[p1] < data[p2]) tmp[p3++] = data[p1++];
			else tmp[p3++] = data[p2++];
		}
		// swap 안된 남은 거 쓸어 담기
		while(p1 <= mid) tmp[p3++] = data[p1++];
		while(p2 <= right) tmp[p3++] = data[p2++];
		for(int i=left; i<=right; i++) 
			data[i] = tmp[i];
}

int main() {
	int n;
	cin >> n;
	for(int i=1; i<=n ; i++) 
		cin >> data[i];

	divide(1, n);

	for(int i=1; i<= n; i++)
		cout << data[i];

	return 0;
}

/** 
Comparison: n times
Tree level: log n
Time Complexity: O(n log n)
**/
