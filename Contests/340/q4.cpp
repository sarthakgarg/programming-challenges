#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
int x[3], y[3];
ll ct = 10;

int main(){
	for(int i = 0; i < 3; i++) cin >> x[i] >> y[i];
	if(x[0] == x[1] && x[1] == x[2] || y[0] == y[1] && y[1] == y[2]){
		cout << "1\n";
		return 0;
	}
	if(x[0] > x[1]){ swap(x[0], x[1]);swap(y[0], y[1]);}
	if(x[0] > x[2]){ swap(x[0], x[2]);swap(y[0], y[2]);}
	if(x[1] > x[2]){ swap(x[1], x[2]);swap(y[1], y[2]);}
	if(x[0] == x[1]){
		if(y[2] < max(y[0], y[1]) && y[2] > min(y[0], y[1])) {cout << "3\n"; return 0;}
		else {cout << "2\n"; return 0;}
	}
	if(x[1] == x[2]){
		if(y[0] < max(y[1], y[2]) && y[0] > min(y[1], y[2])){cout << "3\n"; return 0;}
		else {cout << "2\n"; return 0;}
	}
	cout << "3\n";
	return 0;

}