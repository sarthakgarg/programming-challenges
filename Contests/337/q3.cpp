#include <stdio.h>
#include "iostream"
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include<string.h>
//#include<algorithm.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
#define X first
#define Y second
#define MAXN 1000005
#define MAXALPHA 27
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
char n_set[600][600], p_set[600][600];
int n, ns, k;
void replace(char dst[], char src[], char a, char b, char c, char d){
	int l = strlen(src);
	int k = 0;
	for(int i = 0; i < l; i++){
		if(src[i] == '+'){
			dst[k++] = a;
			dst[k++] = b;
		}
		else{
			dst[k++] = c;
			dst[k++] = d;
		}
	}
	dst[k] = '\0';
}
int main(){
	cin >> n;
	if(n == 0){
		cout << "+\n";
		return 0;
	}
	ns = 2;
	strcpy(n_set[0],"+*");
	strcpy(n_set[1],"++");
	for(int i = 1; i < n; i++){
		int k = 0;
		for(int j = 0; j < ns; j++){
			replace(p_set[k], n_set[j], '+', '+', '*', '*');
			k++;
		}
		for(int j = 0; j < ns; j++){
			replace(p_set[k], n_set[j], '+', '*', '*', '+');
			k++;
		}		
		ns *= 2;
		for(int j = 0; j < ns; j++) strcpy(n_set[j], p_set[j]);
	}
	for(int i = 0; i < ns; i++) cout << n_set[i] << "\n";
	return 0;
}