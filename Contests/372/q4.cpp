#include"iostream"
#include<queue>
#include<stdio.h>
#include<vector>
#include<stack>
#include<map>
#include<string.h>
#include<math.h>
#include<set>
#include<algorithm>
#define N 100000
#define M 150000
#define X first
#define Y second 
#define INF1 10000000007
#define INF2 100000000007
#define INF3 1000000000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
ll n,m,w,x,y,p,parent[1005],l[1005], L, s, t, weight[1001][1001], flag[1003][1003], df, mark[1003][1003];
priority_queue<ii,vector<ii>,greater<ii> > dijk; 
const int mod = 1e9+7;
void print(ll v){
	if(parent[v]==v){return ;}
	mark[v][parent[v]] = 1;
        mark[parent[v]][v] = 1;
	if(df > 0 && flag[v][parent[v]] == 1){
            weight[v][parent[v]] += df;
            weight[parent[v]][v] += df;
            df = 0;
        }
	print(parent[v]);
}
int main(){
	cin >> n >> m >> L >> s >> t;
        REP(i, n)REP(j, n)weight[i][j] = INF2;
	REPP(i,1,m+1){
		cin>>x>>y>>w;
                if(w == 0){
                    w = INF1;
                    flag[x][y] = 1;
                    flag[y][x] = 1;
                }
                weight[x][y] = w;
                weight[y][x] = w;
	}
	REPP(i,0,1003) {l[i]=INF3, parent[i] = -1;}
	l[s]=0;dijk.push(ii(0,s));parent[s]=s;
	while(!dijk.empty()){
		ii v =dijk.top();
		dijk.pop();
		if(l[v.Y]!=v.X) continue;
		for(int j = 0; j < n; j++){
                        if(weight[v.Y][j] == INF2) continue;
			if(v.X + weight[v.Y][j] < l[j]){
				l[j] = v.X + weight[v.Y][j];
				parent[j] = v.Y;
				dijk.push(ii(l[j], j));
			}	
		}
	}
	if(parent[t] == -1 || l[t] < L) {
            cout<<"NO\n";
            return 0;
        }
        REP(i, n)REP(j, n){
                if(weight[i][j] == INF1){
                    weight[i][j] = 1;
                }
	}
	REPP(i,0,1003) {l[i]=INF3, parent[i] = -1;};
        l[s]=0;dijk.push(ii(0,s));parent[s]=s;
	while(!dijk.empty()){
		ii v =dijk.top();
		dijk.pop();
		if(l[v.Y]!=v.X) continue;
		for(int j = 0; j < n; j++){
                        if(weight[v.Y][j] == INF2) continue;
			if(v.X + weight[v.Y][j] < l[j]){
				l[j] = v.X + weight[v.Y][j];
				parent[j] = v.Y;
				dijk.push(ii(l[j], j));
			}	
		}
	}
        
        if(l[t] > L){cout << "NO\n"; return 0;}
        df = L - l[t];
        print(t);
        cout << "YES\n";
        REP(i, n)REPP(j, i + 1, n){
            if(weight[i][j] == INF2) continue;
            if(flag[i][j] == 1 && mark[i][j] == 0) weight[i][j] = INF2;
            cout << i << " " << j << " " << weight[i][j] << "\n";
        }
	return 0;
}	
