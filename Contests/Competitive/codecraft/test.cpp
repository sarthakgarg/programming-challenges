#include<stdio.h>
#include"iostream"
#define N 10023
using namespace std;
void add(int a[], int l, int r){
	return (l > r) ? 0 : a[l] + add(a, l + 1, r);
}
int main(){
	int a[N], b, n;
	cout << "Enter n numbers \n";
	for(int i = 0; i < n; i++) cin >> a[i];
	cout << "Their sum is " << add(a, 0, n - 1) << "\n";
	return 0;
}