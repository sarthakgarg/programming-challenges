#include"iostream"
#include<queue>
#include<stdio.h>
#include<vector>
#include<stack>
#include<stdlib.h>
#include<map>
#include<string.h>
#include<math.h>
#include<set>
#include<unordered_map>
#include<algorithm>
#define B1 237842377
#define M 1000000007
#define X first
#define Y second 
#define INF 1000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
long long hsh(string s){
    long long ret = 0;
    for(int i = 0; i < s.size(); i++){
        ret *= B1;
        ret += s[i];
        ret %= M;
    }
    return ret;
}
set<long long> k;
int main(){
    string x;
    int cnt = 0;
    int collisions = 0;
    while(cin >> x){
        long long chi = hsh(x);
        cout << chi << "\n";
        if(k.find(chi) != k.end()) collisions++;
        else k.insert(hsh(x));
        cnt++;
    }
    cout << collisions << " " << cnt << "\n";
    return 0;
}
