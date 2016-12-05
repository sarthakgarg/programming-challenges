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
#include<cstdio>
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
#define INF 1e9+7;
#define gc getchar_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

const int mod = 1e9+7;
int t,n,x,y,mxx,mxy,mny,mnx,ax[100005],ay[100005],type,pos,posmx,posmn;
int main(){
	scanint(t);
	while(t--){
		scanint(n);
		REPP(i,1,n+1){scanint(x);scanint(y);ax[i]=x;ay[i]=y;}
		mxx = -INF;
		mxy = -INF;
		mnx = INF;
		mny = INF;
		REPP(i,1,n+1){
			mxx = max(mxx, ax[i]);
			mxy = max(mxy, ay[i]);
			mnx = min(mnx, ax[i]);
			mny = min(mny, ay[i]);
		}
		pos=-1;
		REPP(i,1,n+1){
			if(ax[i]==mxx&&ay[i]==mxy){pos = i; type = 1; break;}
			if(ax[i]==mxx&&ay[i]==mny){pos = i; type = 4; break;}
			if(ax[i]==mnx&&ay[i]==mxy){pos = i; type = 2; break;}
			if(ax[i]==mnx&&ay[i]==mny){pos = i; type = 3; break;}
		}
		if(pos!=-1){
			cout<<"1\n";
			if(type==1)cout<<pos<<" SW\n";
			else if(type==2)cout<<pos<<" SE\n";
			else if(type==3)cout<<pos<<" NE\n";
			else cout<<pos<<" NW\n";
		}
		else{
			cout<<"2\n";
			REPP(i,1,n+1){if(ax[i]==mxx)posmx=i;}
			REPP(i,1,n+1){if(i!=posmx&&ax[i]==mnx)posmn=i;}
			if(ay[posmx]>=ay[posmn]){
				cout<<posmx<<" SW\n";
				cout<<posmn<<" NE\n";
			}
			else{
				cout<<posmx<<" NW\n";
				cout<<posmn<<" SE\n";
			}
		}
	}
	return 0;
}