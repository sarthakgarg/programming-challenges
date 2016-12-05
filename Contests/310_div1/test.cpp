#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll i, j;
int main(){
    cout << "1000000000 200000\n";
    ll i = 1000000000, j = 1;
    ll ct = 100000;
    while(ct--){
        cout << j << " " << i << "U\n";
        cout << i << " " << j << "L\n";
        i--;
        j++;
    }
}