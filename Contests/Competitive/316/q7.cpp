#include<stdio.h>
#include"iostream"
using namespace std;
float dp[102][102];
int done[102][102];
float find(int k,int x){
	printf("%d %d\n",k,x );
	if(x==2){
		if(k==1) return 1;
		else return 0;
	}
	if(x==1){
		if(k==1) return 1;
		else return 0;
	}
	if(k==x) return 0;
	if(k==0) return 0;
	if(done[k][x]==1) return dp[k][x];
	done[k][x]=1;
	return dp[k][x]= find(k-1,x-1)*(k-1)/(x-1) + find(k,x-1)*(x-1-k)/(x-1);
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cout<<find(4,8);
	return 0;
}