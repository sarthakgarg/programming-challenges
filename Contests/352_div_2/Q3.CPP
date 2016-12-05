#include<stdio.h>
#include"iostream"
#include<math.h>
#define N 100005
#define INF 2000000007
using namespace std;
double min(double a, double b){return (a > b) ? (b) : (a);}
double ax, ay, bx, by, tx, ty, x, y, adil[N], bera[N], sum, amin = INF, as = INF, bmin = INF, bs = INF;
int n, aminpos, aspos, bminpos, bspos;
int main(){
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        adil[i] = sqrt((ax - x) * (ax - x) + (ay - y) * (ay - y)) - sqrt((tx - x) * (tx - x) + (ty - y) * (ty - y));
        bera[i] = sqrt((bx - x) * (bx - x) + (by - y) * (by - y)) - sqrt((tx - x) * (tx - x) + (ty - y) * (ty - y));
        sum += 2 * sqrt((tx - x) * (tx - x) + (ty - y) * (ty - y));
    }
    for(int i = 0; i < n; i++){
        if(amin > adil[i]){
            amin = adil[i];
            aminpos = i;
        }
    }
    adil[aminpos] = INF - 1;
    for(int i = 0; i < n; i++){
        if(as > adil[i]){
            as = adil[i];
            aspos = i;
        }
    }
    for(int i = 0; i < n; i++){
        if(bmin > bera[i]){
            bmin = bera[i];
            bminpos = i;
        }
    }
    bera[bminpos] = INF - 1;
    for(int i = 0; i < n; i++){
        if(bs > bera[i]){
            bs = bera[i];
            bspos = i;
        }
    }
    if(amin > 0) amin = 0;
    if(bmin > 0) bmin = 0;
    if(as > 0) as = 0;
    if(bs > 0) bs = 0;
    if(bminpos != aminpos) printf("%.7lf\n", sum + amin + bmin);
    else printf("%.7lf\n", sum + min(amin + bs, bmin + as));
    return 0;
}