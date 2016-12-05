#include<stdio.h>
#include"iostream"
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<complex>
#include<map>
#include<vector>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	auto itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const int mod = 1e9+7;
long long i,k,po,n,s;
double ai, bi, x;
double comp(double x, long long po){
	while(po>0){x = x*2; po--;}
	while(po<0 && (x>0.001||x<-0.01)){x = x/2; po++;}
	return x;
}
int main(){
	cin>>i>>k>>s;
	cin>>ai>>bi;
	if(k>i&&(k-i)%2==0){
		po = -s+2*(k-i);
		x = (ai + bi);
	}
	else if(k>i&&(k-i)%2==1){
		po = (-s+2*(k-i)-1);
		x = sqrt(2)*(ai+sqrt(3)*bi);
	}
	else if(k<i&&(i-k)%2==0){
		po = (-s-2*(i-k));
		x = ai + bi;
	}
	else if(k<i&&(i-k)%2==1){
		po = (-s-2*(i-k));
		x = (ai + sqrt(3)*bi)/sqrt(2);
	}
	else if(k==i){
		po = -s;
		x = (ai + bi);
	}
	printf("%.6lf\n",comp(x, po));
	return 0;
}