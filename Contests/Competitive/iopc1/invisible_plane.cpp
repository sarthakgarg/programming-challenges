#include<stdio.h>
#include"iostream"
#include<algorithm>
#define N 200005
#define X first
#define Y second
#define INF 20000000000540
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
ii b[N];
ll a[N], l, r, x, n, m, q, y, z;

struct data {
	ll sum, pref, suff, ans;
};

data t[4 * N];

data combine (data l, data r) {
	data res;
	res.sum = l.sum + r.sum;
	res.pref = max (l.pref, l.sum + r.pref);
	res.suff = max (r.suff, r.sum + l.suff);
	res.ans = max (max (l.ans, r.ans), l.suff + r.pref);
	return res;
}


data make_data (ll val) {
	data res;
	res.sum = val;
	res.pref = res.suff = res.ans = val;
	return res;
}

void build (ll a[], ll v, ll tl, ll tr) {
	if (tl == tr)
		t[v] = make_data (a[tl]);
	else {
		ll tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		t[v] = combine (t[v*2], t[v*2+1]);
	}
}

void update (ll v, ll tl, ll tr, ll pos, ll new_val) {
	if (tl == tr)
		t[v] = make_data (new_val);
	else {
		ll tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);
		t[v] = combine (t[v*2], t[v*2+1]);
	}
}

data query (ll v, ll tl, ll tr, ll l, ll r) {
	if (l == tl && tr == r)
		return t[v];
	ll tm = (tl + tr) / 2;
	if (r <= tm)
		return query (v*2, tl, tm, l, r);
	if (l > tm)
		return query (v*2+1, tm+1, tr, l, r);
	return combine (
		query (v*2, tl, tm, l, tm),
		query (v*2+1, tm+1, tr, tm+1, r)
	);
}

typedef struct qu{
  ll lt;
  ll rt;
  ll in;
  ll xt;
  ll ans;
} str;

bool cmpfunc(str l, str r){
  return (l.xt > r.xt);
}

bool cmpfunc2(str l, str r){
  return (l.in < r.in);
}
str queries[N];
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n >> q;
  for(ll i = 0; i < n; i++){
    cin >> a[i];
    b[i] = ii(a[i], i);
  }
  for(ll i = 0; i < q; i++){
    cin >> queries[i].lt >> queries[i].rt >> queries[i].xt;
    queries[i].lt--;
    queries[i].rt--;
    queries[i].in = i;
    queries[i].ans = 0;
  }
  build(a, 1, 0, n - 1);
  sort(queries, queries + q, cmpfunc);
  sort(b, b + n);
  ll pt = n - 1;
  for(ll i = 0; i < q; i++){
    ll xp = queries[i].xt;
    while(pt >= 0 && b[pt].X > xp) {
      update(1, 0, n - 1, b[pt].Y, -INF);
      pt--;
    }
    queries[i].ans = query(1, 0, n - 1, queries[i].lt, queries[i].rt).ans;
  }
  sort(queries, queries + q, cmpfunc2);
  for(ll i = 0; i < q; i++){
    if(queries[i].ans == -INF) cout << "xx\n";
    else cout << queries[i].ans << "\n";
  }
}
