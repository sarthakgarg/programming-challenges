//coding basix dfs
#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 100005
#define mod 1000000007
#define X first
#define Y second 
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
vector<int> adj[N];
int n, x, y, sum[N], visit[N];
float ex[N];
void dfs1(int v){
    visit[v] = 1;
    int x = 0;
    foreach(adj[v], it){
        if(visit[*it] == 0){
            dfs1(*it);
            x += sum[*it];
        }
    }
    sum[v] = x + 1;
}
void dfs2(int v, float p){
    visit[v] = 1;
    ex[v] = p;
    foreach(adj[v], it){
        if(visit[*it] == 0){
            dfs2(*it, p + 1 + 1.0 * (sum[v] - 1 - sum[*it]) / 2);
        }
    }
}
int main(){
    int n;
    cin >> n;
    REPP(i, 2, n + 1){
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    dfs1(1);
    REPP(i, 1, n + 1) visit[i] = 0;
    ex[1] = 1.0;
    dfs2(1, 1.0);
    REP(i, n) printf("%.6f ", ex[i + 1]);
    cout << "\n";
    return 0;
}