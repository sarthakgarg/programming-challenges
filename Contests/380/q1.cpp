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
int main(){
    int n;
    string s, t;
    cin >> n;
    cin >> s;
    for(int i = 0; i < n;){
        int j = i;
        if(j + 2 <= n - 1 && s[j] == 'o' && s[j + 1] == 'g' && s[j + 2] == 'o'){
            j += 3;
            while(j + 1 <= n - 1 && s[j] == 'g' && s[j + 1] == 'o') j += 2;
        }
        if(j != i){
            t += "***";
            i = j;
        }
        else{
            t.push_back(s[i]);
            i++;
        }
    }
    cout << t << "\n";
    return 0;
}