#include<stdio.h>
#include"iostream"
#include<string>
using namespace std;
string bit = "1111111111111111111111111111111";
int main(){
	bit[9]='0';
	cout<<bit.size()<<" "<<bit<<"\n";
	return 0;
}