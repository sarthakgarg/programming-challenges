#include<stdio.h>
#include"iostream"
#include<algorithm>
#define X first
#define Y second
#define N 102
using namespace std;
typedef long long ll;
pair<int, int> a[N];
int main(){
    int n, x;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        a[i - 1].X = x;
        a[i - 1].Y = i;
    }
    sort(a, a + n);
    for(int i = 0; i < n / 2; i++){
        cout << a[i].Y << " " << a[n - 1 - i].Y << "\n";
    }
    return 0;
}.