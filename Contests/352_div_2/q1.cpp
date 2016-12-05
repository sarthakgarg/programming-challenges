#include<stdio.h>
#include "iostream"
#include<stack>
#define N 1000
#define X first
#define Y second
typedef long long ll;
using namespace std;
int main(){
    int n, m = 1, x, y;
    stack<int> dig;
    cin >> n;
    while(1){
        int t = m;
        while(t != 0){
            dig.push(t % 10);
            t /= 10;
        }
        m++;
        while(!dig.empty()){
            x = dig.top();
            dig.pop();
            if(n == 1) {
                cout << x << "\n";
                return 0;
            }
            n--;
        }
    }
}