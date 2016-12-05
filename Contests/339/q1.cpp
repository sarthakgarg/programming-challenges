#include <stdio.h>
#include "iostream"
#include <string.h>
#include <math.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
int n;
double x[1000006], y[1000006], xp, yp;
double r_min, area, temp, r_max;
const double PI  =3.141592653589793238463;
double dot(double x1, double y1, double x2, double y2){
	return (x1 * x2 + y1 * y2);
}
double ab(double x){
	if(x < 0) return -x;
	else return x;
}
int main(){
	cin >> n >> xp >> yp;
	r_min = 100000000000000000;
	r_max = -1;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	x[n] = x[0];
	y[n] = y[0];
	for(int i = 0; i < n; i++){
		if((dot(x[i + 1] - x[i], y[i + 1] - y[i], x[i + 1] - xp, y[i + 1] - yp)) < 0 || dot(x[i] - x[i + 1], y[i] - y[i + 1], x[i] - xp, y[i] - yp) < 0){
			temp = (x[i] - xp) * (x[i] - xp) + (y[i] - yp) * (y[i] - yp);
			temp = sqrt(temp);
			r_max = max(r_max, temp);
			r_min = min(r_min, temp);
			temp = (x[i + 1] - xp) * (x[i + 1] - xp) + (y[i + 1] - yp) * (y[i + 1] - yp);
			temp = sqrt(temp);
			r_max = max(r_max, temp);
			r_min = min(r_min, temp);
		}
		else{
		//	cout << "case " << i << "\n";
			temp = (x[i] - xp) * (x[i] - xp) + (y[i] - yp) * (y[i] - yp);
			temp = sqrt(temp);
			r_max = max(r_max, temp);
			temp = (x[i + 1] - xp) * (x[i + 1] - xp) + (y[i + 1] - yp) * (y[i + 1] - yp);
			temp = sqrt(temp);
			r_max = max(r_max, temp);
			double t, x1 = x[i], x2 = x[i+ 1], y1 = y[i], y2 = y[i + 1], nr, dr;
			dr = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
			dr = sqrt(dr);
			t = ab(yp * (x2 - x1) - xp * (y2 - y1) - y2 * (x2 - x1) + x2 * (y2 - y1));
			nr = t;
			r_min = min(r_min, nr / dr);
		//	cout << i << " " << r_min << "\n";
		}
	}
	printf("%.14lf\n", (double)(r_max * r_max - r_min * r_min) * PI);
	return 0;
}