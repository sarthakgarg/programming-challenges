#include"iostream"
#include<queue>
#include<map>
#include<string.h>
#include<vector>
#include<stack>
#include<stdio.h>
#include<math.h>
#include<set>
#include<algorithm>
#define N 100005
#define M 150000
#define mod 10000007
#define MIN -1000000000
#define X first
#define Y second 
#define INF 1000000000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
int lft, rgt, top, bot, n, x;
char str[12];
int main(){
    cin >> n >> str;
    REP(i, n){
        if(str[i] == '1' || str[i] == '2' || str[i] == '3') top++;
        if(str[i] == '1' || str[i] == '4' || str[i] == '7' || str[i] == '0') lft++;
        if(str[i] == '3' || str[i] == '6' || str[i] == '9' || str[i] == '0') rgt++;
        if(str[i] == '7' || str[i] == '0' || str[i] == '9') bot++;
    }
    if(lft > 0 && rgt > 0 && top > 0 && bot > 0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}