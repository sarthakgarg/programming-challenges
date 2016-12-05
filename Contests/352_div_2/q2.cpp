#include<stdio.h>
#include"iostream"
#include<string.h>
#define N 100005
using namespace std;
typedef long long ll;
char str[N];
int n, frq[150], m = 0;
int main(){
    cin >> n;
    cin >> str;
    if(strlen(str) > 26) cout << "-1\n";
    else{
        for(int i = 0; str[i] != '\0'; i++){
            frq[str[i]]++;
        }
        for(int i = 'a'; i <= 'z'; i++) m += (frq[i] > 1) ? (frq[i] - 1) : 0;
        cout << m << "\n";
    }
    return 0;
}