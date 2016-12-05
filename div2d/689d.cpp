// for each element of an array, the number of subarrays having that number as max are to be counted. Binary search + segtree is used for this purpose
#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 200005
#define mod 1000000007
#define X first
#define Y second 
#define INF 1000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef struct m{
    int val;
    int pos;
}mx;
mx t[4 * N];
int a[N], b[N];
map<int, int> ac, bc;
mx merge(mx a, mx b){
    mx ans;
    ans.val = max(a.val, b.val);
    if(a.val >= b.val) ans.pos = a.pos;
    else ans.pos = b.pos;
    return ans;
}
void build(int v, int tl, int tr, int ar[]){
    if(tl == tr) {
        t[v].val = ar[tl];
        t[v].pos = tl;
        return;
    }
    int mid = (tl + tr) / 2;
    build(2 * v, tl, mid, ar);
    build(2 * v + 1, mid + 1, tr, ar);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

mx query(int v, int tl, int tr, int l, int r){
    if(l > r){
        mx id = {-INF, -1};
        return id;
    }
    else if(tl == l && tr == r) return t[v];
    int mid = (tl + tr) / 2;
    return merge(query(2 * v, tl, mid, l, min(mid, r)), query(2 * v + 1, mid + 1, tr, max(mid + 1, l), r));
}
map<int, int> compute(int ar[], int n){
    map<int, int> ct;
    REP(x, n){
        int lo = 0, hi = x, mid;
        while(lo < hi){
            mid = (lo + hi) / 2;
            int y = query(1, 0, n - 1, mid, x).pos;
            if(y == x) hi = mid;
            else lo = mid + 1;
        }
        int lidx = lo;
        lo = x;
        hi = n - 1;
        while(lo < hi){
            mid = lo + (hi - lo + 1) / 2;
            int y = query(1, 0, n - 1, x, mid).pos;
            if(y == x) lo = mid;
            else hi = mid - 1;
        }
        int hidx = lo;
        if(ct.find(ar[x]) == ct.end()) ct[ar[x]] = 0;
        ct[ar[x]] += (x - lidx + 1) * (hidx - x + 1);
    }
    return ct;
}
int main(){
    int n;
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n){
        cin >> b[i];
        b[i] = -b[i];
    }
    build(1, 0, n - 1, a);
    ac = compute(a, n);
    build(1, 0, n - 1, b);
    bc = compute(b, n);    
    int sum = 0;
    foreach(ac, it){
        sum += (it->Y) * bc[-it->X]; 
    }
    cout << sum << "\n";
    return 0;
}