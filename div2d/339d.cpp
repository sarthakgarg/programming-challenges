//Coding the most basic segtree
#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 150000
#define X first
#define Y second 
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
int t[4 * N], a[N];
int build(int v, int tl, int tr, int a[]){
    if(tl == tr){
        t[v] = a[tl];
        return 1;
    }
    int mid = (tl + tr) / 2, x;
    x = build(2 * v, tl, mid, a);
    x = build(2 * v + 1, mid + 1, tr, a);
    if(x == 1){
        t[v] = t[2 * v] | t[2 * v + 1];
    }
    else t[v] = t[2 * v] ^ t[2 * v + 1];
    return -x;
}

int update(int v, int tl, int tr, int pos, int val){
    if(tl == tr){
        t[v] = val;
        return 1;
    }
    int mid = (tl + tr) / 2, x;
    if(pos <= mid) x = update(2 * v, tl, mid, pos, val);
    else x = update(2 * v + 1, mid + 1, tr, pos, val);
    if(x == 1) t[v] = t[2 * v] | t[2 * v + 1];
    else t[v] = t[2 * v] ^ t[2 * v + 1];
    return -x;
}
int n, m, p, v;
int main(){
    cin >> n >> m;
    REP(i, 1 << n){
        cin >> a[i];
    }
    build(1, 0, (1 << n) - 1, a);
    REP(i, m){
        cin >> p >> v;
        update(1, 0, (1 << n) - 1, p - 1, v);
        cout << t[1] << "\n";
    }
    return 0;
}