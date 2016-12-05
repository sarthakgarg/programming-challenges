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
#define INF 1000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
ll n, a[N], c[N], ct = 1, ans;
vector<int> change;
int main(){
    cin >> n;
    REPP(i, 1, n + 1) cin >> a[i];
    REPP(i, 1, n + 1){
        if(c[i] != 0) continue;
        int j = i;
        while(c[j] == 0){
            c[j] = ct;
            j = a[j];
        }
        if(c[j] == c[i]) change.push_back(j);
        ct++;
    }
    foreach(change, it){
        if(a[*it] == *it) {
            swap(*it, *(change.begin()));
            ans = -1;
        }
    }
    foreach(change, it){
        if(it != change.begin()) a[*it] = *(it - 1);
        else a[*it] = *it;
    }
    cout << change.size() + ans << "\n";
    REPP(i, 1, n + 1) cout << a[i] << " ";
    cout << "\n";
}