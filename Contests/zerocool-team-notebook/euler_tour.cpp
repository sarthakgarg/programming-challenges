/*The following code finds an euler tour
Input graph in the form of adjacency matrix because of the deletion of edges, the graph be multi-graph
O(m) time
O(n^2) space
O(m) recursion depth
Caution : This algorithm only works correctly if the graph is connected
Verified*/
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
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
stack<int> tour;
int edj[1000][1000];
const int mod = 1e9+7;
int n, m, p, q, x, y, degree[1000];
void find_tour(int v){
	REPP(i,1,n+1){
		while(edj[v][i]>0){
			edj[v][i]--;
			edj[i][v]--;
			find_tour(i);
		}
	}
	tour.push(v);
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	REP(i, m){
		cin>>x>>y;
		edj[x][y]++;
		edj[y][x]++;
		degree[x]++;
		degree[y]++;
	}
	REPP(i,1,n+1){
		if(degree[i]%2==1){
			cout<<"No euler tour\n";
			return 0;
		}
		if(degree[i]) x = i;
	}
	cout<<"euler tour exists \n";
	find_tour(x);
	while(!tour.empty()){
		cout<<tour.top()<<" ";
		tour.pop();
	}
	return 0;
}