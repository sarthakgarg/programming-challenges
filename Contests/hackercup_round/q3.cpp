#include<stdio.h>
#include"iostream"
#include<stack>
#include<vector>
#include<map>
 
using namespace std;

#define INF 1000000007
#define MAX 200010 
#define BIG 1000000000
#define EPS 0.000001
#define pi  2*acos(0)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef pair<ii,ii> pii;
 
#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
vector<pair<ll,ll> > V;
ll tempi[MAX+1][3];
int main() {
  fast; 
  //freopen("input.txt","r",stdin);
  //freopen("abc.txt","w",stdout);
  int t;
  cin>>t;
  FOR(z,1,t){
    int n;
    V.clear();
    memset(tempi,0,sizeof(tempi));
    int a,b;
    cin>>n;
    FOR(i,0,n-1){
      cin>>a>>b;
      V.pb(mp(a,b));
    }
    sort(all(V));
    stack<int> s;
    ll ans=0;
    s.push(0);
    tempi[0][0]=1;
    tempi[0][1]=(V[0].F*V[0].F)%INF;
    tempi[0][2]=V[0].F;
    FOR(i,1,n-1){
      while(!s.empty()&&V[i].S>V[s.top()].S){
        s.pop();
      }
      if(!s.empty()&&V[i].S==V[s.top()].S){
        ll temp=(V[i].F*V[i].F)%INF;
        temp=(temp*tempi[s.top()][0])%INF;
        ans=ans+temp;if(ans>=INF)ans-=INF;
        ans=ans+tempi[s.top()][1];if(ans>=INF)ans-=INF;
        temp=(-(tempi[s.top()][2])*2*(V[i].F))%INF;
        while(temp<0)temp+=INF;
        ans=ans+temp;if(ans>=INF)ans-=INF;
        tempi[i][0]=tempi[s.top()][0]+1;
        tempi[i][1]=tempi[s.top()][1]+(V[i].F*V[i].F)%INF;if(tempi[i][1]>=INF)tempi[i][1]-=INF;
        tempi[i][2]=tempi[s.top()][2]+V[i].F;if(tempi[i][2]>=INF)tempi[i][2]-=INF;
        s.pop();
      }
      else{
        tempi[i][0]=1;
        tempi[i][1]=(V[i].F*V[i].F)%INF;
        tempi[i][2]=V[i].F;
      }
      //cout<<ans<<"\n";
      s.push(i);
    }
    cout<<"Case #"<<z<<": "<<ans<<"\n";  
  }
  return 0;
} 
