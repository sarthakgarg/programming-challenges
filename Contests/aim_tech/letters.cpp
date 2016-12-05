#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<string.h>
#include<set>
#include<algorithm>
#define N 100005
#define mod 1000000007
#define X first
#define Y second 
#define INF 1000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
char str[N];
int x, y, z;
int main(){
    cin >> str;
    x = strlen(str);
    for(y = 0; str[y] != '\0'; y++) if(str[y] != 'a') break;
    if(y == x) str[x - 1] = 'z';
    else{
        REPP(i, y, x) if(str[i] == 'a') break; else str[i]--;
    }
    cout << str << "\n";
    return 0;
}