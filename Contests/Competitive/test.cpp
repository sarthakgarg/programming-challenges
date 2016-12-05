#include<stdio.h>
#include"iostream"
using namespace std;
int main(){
	char ch;
	int count=0;
	while(scanf("%c",&ch)==1){if(ch=='R') count++;}
	cout<<count;
}	