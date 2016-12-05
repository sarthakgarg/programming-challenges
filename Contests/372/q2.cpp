#include"iostream"
#include<queue>
#include<stdio.h>
#include<vector>
#include<stack>
#include<map>
#include<string.h>
#include<math.h>
#include<set>
#include<algorithm>
#define N 50006
#define M 150000
#define mod 1000000007
#define X first
#define Y second 
#define INF 1000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
char str[N];
ll alpha[29], n, x, y, z, flag;
int main(){
    cin >> str;
    for(int i = 0; str[i] != '\0'; i++){
        for(int j = 0; j < 26; j++) alpha[j] = 0;
        flag = 0;
        for(int j = i; j < i + 26; j++){
            if(str[j] == '\0' || alpha[str[j] - 'A'] == 1){
                flag = 1;
                break;
            }
            else if(str[j] != '?') alpha[str[j] - 'A'] = 1;
        }
       // cout << i << " " << flag << "\n";
        if(flag == 0){
            int k = 0;
            while(alpha[k] == 1)k++;
            for(int j = i; j < i + 26; j++){
                if(str[j] == '?'){
                    str[j] = 'A' + k;
                    alpha[k] = 1;
                    while(alpha[k] == 1)k++;
                }
            }
            break;
        }
    }
    if(flag == 1) cout << "-1\n";
    else{
        for(int i = 0; str[i] != '\0'; i++) if(str[i] == '?') str[i] = 'A';
        cout << str << "\n";
    }
    return 0;
}   