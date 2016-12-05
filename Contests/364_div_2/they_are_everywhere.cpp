#include<stdio.h>
#include "iostream"
#define N 100005
#define X first
#define Y second
typedef long long ll;
using namespace std;
int frq[150], x, y, mn = N, n;
char str[N];
int main(){
    cin >> n >> str;
    for(int i = 0; i < n; i++) frq[str[i]]++;
    for(y = n - 1; frq[str[y]] != 1; y--) frq[str[y]]--;
    mn = y + 1;
    
    for(x = 0; x < n; x++){
        frq[str[x]]--;
        if(frq[str[x]] == 0){
            while(1){
                if(y == n - 1) {cout << mn << "\n"; return 0;};
                y++;
                frq[str[y]]++;
                if(frq[str[x]] != 0){
                    break;
                }
            }
        }
        mn = min(mn, y - x);
    }
    cout << mn << "\n";
    return 0;
}