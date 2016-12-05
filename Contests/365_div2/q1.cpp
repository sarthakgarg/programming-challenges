#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 1000005
#define mod 1000000007
#define X first
#define Y second
#define INF 1000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
int main(){
        int m = 0, c = 0, n, x, y;
        cin >> n;
        REP(i, n){
            cin >> x >> y;
            if(x > y) m++;
            else if(y > x) c++;
        }
        if(m > c) cout << "Mishka\n";
        else if(c > m) cout << "Chris\n";
        else cout << "Friendship is magic!^^\n";
        return 0;
}