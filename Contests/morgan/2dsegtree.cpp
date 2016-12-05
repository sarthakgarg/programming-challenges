#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<unordered_map>
#include <unordered_set>
#define N 1002
#define M 100000
#define mod 1000000007
#define X first
#define Y second
#define INF 1000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
int t[4 * N][4 * N], a[N][N];

void build(int vx, int vy, int tlx, int trx, int tly, int try){
    if(tlx != trx){
        int midx = (tlx + trx) / 2;
        build(2 * vx, vy, tlx, midx, tly, try);
        build(2 * vx + 1, vy, midx + 1, trx, tly, try);
        t[vx][vy] = t[2 * vx][vy] + t[2 * vx + 1][vy];
    }
    else if(tly != try){
        int midy = (tly + try) / 2;
        build(vx, 2 * vy, tlx, trx, tly, midy);
        build(vx, 2 * vy + 1, tlx, trx, midy + 1, try);
        t[vx][vy] = t[vx][2 * vy] + t[vx][2 * vy + 1];
    }
    else{
        t[vx][vy] = a[tlx][tly];
    }
    return;
}

void update(int vx, int vy, int tlx, int trx, int tly, int try, int x, int y){
    if(tlx == trx && tlx == x && tly == try && tly == y){
        t[vx][vy]++;
    }
    else if(tlx != trx){
        int midx = (tlx + trx) / 2;
        if(x <= midx) update(2 * vx, tlx, midx, tly, try, x, y);
        else update()
    }
}
int main(){
    
}
