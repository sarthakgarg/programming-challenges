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
#define N 200005
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
ll d[N], x, y, a, n; 
queue<int> q;
vector<int> adj[N];
int main(){
    cin >> n;
    REPP(i, 1, n + 1){
        d[i] = N;
        cin >> x;
        adj[i].push_back(x);
        if(i != n) adj[i].push_back(i + 1);
        if(i != 1) adj[i].push_back(i - 1);
    }
    q.push(1);
    d[1] = 0;
    while(!q.empty()){
        x = q.front();
        q.pop();
        foreach(adj[x], it){
            if(d[*it] == N){
                d[*it] = d[x] + 1;
                q.push(*it);
            }
        }
    }
    REPP(i, 1, n + 1) cout << d[i] << " ";
    cout << "\n";
}