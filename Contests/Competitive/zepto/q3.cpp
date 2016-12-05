
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
int gcd(ll a,ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
ll max(ll a,ll b){
	if(a>b) return a;
	else return b;
}
int main(){
	ll c,hr,hb,wr,wb,x,y;
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>c>>hr>>hb>>wr>>wb;
	ll ans=0,lcm,mx=0;
	lcm=wr*wb;
	if(hr*wb>=hb*wr)ans=(c/lcm)*(lcm/wr)*hr;
	else ans=(c/lcm)*(lcm/wb)*hb;
	c=c%lcm;
	cout<<ans<<" "<<c<<"\n";
	if(wr>=wb){
		ll ct=0;
		while(c>=ct*wr){mx=max(mx,ct*hr+((c-ct*wr)/wb)*hb);ct++;}
	}	
	else{
		ll ct=0;
		while(c>=ct*wb){mx=max(mx,ct*hb+((c-ct*wb)/wr)*hr);ct++;}
	}	
	cout<<ans+mx<<"\n";
	return 0;
}	