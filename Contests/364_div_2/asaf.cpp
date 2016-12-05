#include<stdio.h>
#include "iostream"
using namespace std;
#define N 10004
double min(double a, double b){return (a < b) ? a : b;}
int n, l, v1, v2, k;
int check(double mid){
    int n1 = n - k;
    double x1 = v1 * mid / v2, x2 = mid;
    if(n1 <= 0){
        if(x2 > l) return 1;
        else return -1;
    }
    while(1){
        double t = (x2 - x1) / (v1 + v2);
        x2 += t * v1;
        x1 += t * v1;
        n1 -= k;
        t = (x2 - x1) / (v2 - v1);
        x2 += t * v1;
        x1 += t * v1;
        if(n1 <= 0){
            if(x2 > l) return 1;
            else return -1;
        }
    }
}

int main(){
    double dist = 0, time = 0;
    cin >> n >> l >> v1 >> v2 >> k;
    double lo = 0, hi = l, mid;
    int iter = 100;
    while(iter--){
        mid = (lo + hi) / 2;
        if(check(mid) == 1) hi = mid;
        else lo = mid;
    }
    printf("%.6lf\n",1.0 * (mid) / v2 + (l - mid) / v1);
    return 0;
}