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
#define N 1003
#define M 150000
#define mod 1000000007
#define X first
#define Y second 
#define INF 1000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
char str[N][6], s[6];
int n, m, flag = 1;
int main(){
    cin >> n;
    REP(i, n){
        cin >> s;
        if(s[0] == 'O' && s[1] == 'O' && flag == 1){
            flag = 0;
            s[0] = s[1] = '+';
        }
        if(s[3] == 'O' && s[4] == 'O' && flag == 1){
            flag = 0;
            s[3] = s[4] = '+';
        }
        strcpy(str[i], s);
    }
    if(flag == 0){
        cout << "YES\n";
        REP(i, n) cout << str[i] << "\n";
    }
    else cout << "NO\n";
    return 0;
}