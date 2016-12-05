#include<stdio.h>
#include"iostream"
#define N 100000
using namespace std;
typedef long long ll;
int a[N], c[N];
void merge(int a[], int x, int y, int l, int r){
	int i = x, j = l, k = 0;
	while(i <= y && j <= r){
		if (a[i] <= a[j]) c[k++] = a[i++];
		else c[k++] = a[j++];
	}
	while(i <= y) c[k++] = a[i++];
	while(j <= r) c[k++] = a[j++];
	for(int i = 0; i < k; i++) a[i + x] = c[i];
}
void sort(int a[], int l, int r){
	if(l == r) return;
	int mid = (l + r) / 2;
	sort(a, l, mid);
	sort(a, mid + 1, r);
	merge(a, l, mid, mid + 1, r);
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, 0, n - 1);
	for(int i = 0; i < n; i++) cout << a[i];
	return 0;
}	

