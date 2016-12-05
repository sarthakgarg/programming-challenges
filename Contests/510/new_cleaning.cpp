#include<stdio.h>
#include"iostream"
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
#define N 100006
int n, h, w, lt[N], rt[N], up[N], dn[N], s, mx, tl, tu, td, tr, blt[N], brt[N], bup[N], bdn[N], dis;
char arr[2*N];
int main(){
	cin >> n >> h >> w;
	cin >> arr;
	strcat(arr, arr);
	s = 0;
	mx = 0;
	for(int i = 0; i < 2*n; i++){
		if(arr[i] == 'R') s++;
		else if(arr[i] == 'L') s--;
		mx = max(mx, s);
		rt[i] = mx;
		brt[i] = s;
	}
	int cyc_dis = s;
	int cyc_mx = mx;
	int ind = -1;
	int tol_r = 0;
	while(h != 0 || w != 0){
		int base = (ind == -1) ? (0) : brt[ind];
		int r_time;
		if(tol_r + base > cyc_mx){
			if(cyc_dis > 0){
				r_time += n*
			}
		}
	}
}