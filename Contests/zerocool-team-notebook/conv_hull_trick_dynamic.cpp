// This is a fully dynamic variant of the convex hull problem. The search range is 0 to INF 
// The search is > 0
// lines added by the add function, min envelope value searched by the query function. 
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
typedef pair<ll, ll> ii;
typedef pair<ii, double> inv;
#define INF 1e18+7
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( auto itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
ll inf = 1000000000000000000;
ll gcd(ll a, ll b){
	return (b == 0) ? a : gcd(b, a % b);
}
ll ab(ll a){
	return (a<0) ? (-a) : a;
}
typedef pair<ii, ii> line;
bool cmp(ii p1, ii p2){
    return (((double)p1.X / (double)p1.Y) < ((double)p2.X / (double)p2.Y));
 };
map <ii, ii, std::greater<ii> > st;
map <ii, ii, bool(*)(ii, ii)> pt(cmp);
bool ins;
ll m, n, k, p, q, r, s, t, b, s1, t1, ran, slope1, inter1, slope2, inter2,counter, x;
void add(ll m, ll b) {
	ii point;
	auto l1 = st.begin();
	auto l2 = st.begin();
	auto l3 = st.begin();
	auto l4 = st.begin();
	auto l5 = st.begin();	
	auto l3t = st.begin();
	if(st.find(ii(m, b)) != st.end()) return;
	st[ii(m, b)] = ii(-1, -1);
	l3 = st.find(ii(m, b));
	// first remove degeneracy
	l3t = l3;
	l4 = ++l3t;
	if(l4 != st.end()){
		if(l3->X.Y >= l4->X.Y){
			st.erase(l3);
			return;
		}
	}
	// standardize to 0
	while(1){
		if(l3 == st.begin()) break;
		l3t = l3;
		l2 = --l3t;
		if(l2->X.Y >= l3->X.Y){
			pt.erase(l2->Y);
			st.erase(l2);
		}
		else break;
	}

	// now remove the lines of the type l4. 
	while(1){
		l3t = l3;
		l4 = ++l3t;
		if(l4 == st.end()) break;
		l5 = ++l3t;
		if(l5 == st.end()) break;
		if(((double)( l3->X.Y - l5->X.Y) / (double)(l5->X.X - l3->X.X)) <= ((double)(l3->X.Y - l4->X.Y) / (double)(l4->X.X - l3->X.X))){
			pt.erase(l4->Y);		
			st.erase(l4);
		}
		else break;
	}
	// now remove the lines of the type l2
	while(1){
		if(l3 == st.begin()) break;
		l3t = l3;
		l2 = --l3t;
		if(l2 == st.begin()) break;
		l1 = --l3t;
		if(((double)( l1->X.Y - l3->X.Y) / (double)(l3->X.X - l1->X.X)) <= ((double)(l1->X.Y - l2->X.Y) / (double)(l2->X.X - l1->X.X))){
			pt.erase(l2->Y);		
			st.erase(l2);
		}
		else break;
	}
	// recalculate the values for l3, l4, l5
	l3t = l3;
	l4 = ++l3t;
	if(l4 != st.end()){
		pt.erase(l4->Y);
		ll numr = ab(l4->X.Y - l3->X.Y);
		ll demr = ab(l4->X.X - l3->X.X);
		ll gc = gcd(numr, demr);	
		numr /= gc;
		demr /= gc;
		l4->Y = ii(numr, demr);
		pt[ii(numr, demr)] = l4->X;
	}
	if(l3 == st.begin()){
		l3->Y = ii(0, 1);
		pt[ii(0, 1)] = ii(m, b);
	}
	else{
		l3t = l3;
		l2 = --l3t;	
		ll numr = ab(l2->X.Y - l3->X.Y);
		ll demr = ab(l2->X.X - l3->X.X);
		ll gc = gcd(numr, demr);
		numr /= gc;
		demr /= gc;
		l3->Y = ii(numr, demr);
		pt[ii(numr, demr)] = ii(m, b);
	}
}

ll query(ll y) {          // x should be greater than 0 and then line set should not be empty 
	cout << "set ";
	foreach(pt, it) cout << "(" << it -> X.X << " " << it ->X.Y <<") "<<" -> "<<"("<<it->Y.X<<" "<<it->Y.Y<<") ";   
 	auto it = pt.lower_bound(ii(y, 1));
 	// keep in mind the compare function of the pt set.
   	//it--;
 	ll slope = it->Y.X;
 	ll inter = it->Y.Y;
 	return (inter + y*slope);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while(1){
		cin >> p;
		if(p == 0){
			cin >> m >> b;
			add(m, b);
		}
		else{
			cin >> x;
			cout << query(x) << "\n";
		}
	}
	return 0;
}