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
#define N 1000005
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
ll n, m, x, y, a, b, c, d, e, f, t[N], ct, v[N];
char str, in[15], out[15];
priority_queue<ll, vector<ll>, greater<ll> > lis;
int main(){
    cin >> n;
    REP(i, n){
        cin >> in;
        if(in[0] == 'i'){
            cin >> x;
            lis.push(x);
            t[ct++] = 0;
            v[ct - 1] = x;
        }
        else if(in[0] == 'r'){
            if(!lis.empty()){
                lis.pop();
            }
            else{
                t[ct++] = 0;
                v[ct - 1] = MIN;
            }
            t[ct++] = 2;
        }
        else if(in[0] == 'g'){
            cin >> x;
            while(!lis.empty() && lis.top() < x){
                t[ct++] = 2;
                lis.pop();
            }
            if(!lis.empty() && lis.top() == x);
            else{
                t[ct++] = 0;
                v[ct - 1] = x;
                lis.push(x);
            }
            t[ct++] = 1;
            v[ct - 1] = x;
        }
    }
    cout << ct << "\n";
    REP(i, ct){
        if(t[i] == 0){
           cout << "insert " << v[i] << "\n"; 
        }
        else if(t[i] == 1) cout << "getMin " << v[i] << "\n";
        else cout << "removeMin\n";
    }
    return 0;
}