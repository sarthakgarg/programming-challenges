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
#define MAXN 6000000
#define MAXALPHA 2
#define mod 1000000007
#define X first
#define Y second
#define INF 10000000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
int trie[MAXN][MAXALPHA], nxt = 1, cnt[MAXN][MAXALPHA], q, x;
char str[2];
void add(int x){
    int bit = 30;
    int v = 0;
    while(bit >= 0){
        int k = ((x & (1 << bit)) != 0) ? 1 : 0;
        cnt[v][k]++;
        if(trie[v][k] != -1) v = trie[v][k];
        else{
            trie[v][k] = nxt;
            v = nxt;
            nxt++;
        }
        bit--;
    }
}
void subtract(int x){
    int bit = 30;
    int v = 0;
    while(bit >= 0){
        int k = ((x & (1 << bit)) != 0) ? 1 : 0;
        cnt[v][k]--;
        if(trie[v][k] != -1) v = trie[v][k];
        else{
            trie[v][k] = nxt;
            v = nxt;
            nxt++;
        }
        bit--;
    }
}
int count(int x){
    int bit = 30;
    int v = 0;
    int ans = 0;
    while(bit >= 0){
        int k = ((x & (1 << bit)) != 0) ? 0 : 1;
        if(cnt[v][k] > 0){
            v = trie[v][k];
            ans += (1 << bit);
        }
        else{
            if(k == 0) k = 1;
            else k = 0;
            v = trie[v][k];
        }
        bit--;
    }
    return ans;
}

int main(){
    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXALPHA; j++)
            trie[i][j] = -1;
    add(0);
    cin >> q;
    while(q--){
        cin >> str >> x;
        if(str[0] == '+') add(x);
        else if(str[0] == '-') subtract(x);
        else cout << count(x) << "\n";
    }
    return 0;
}