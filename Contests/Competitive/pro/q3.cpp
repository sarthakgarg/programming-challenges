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
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const int mod = 1e9+7;
#define INF 1e9
int n,m,t,x,y,p,q, w[20],parent[20][20],dp[300000],bit[40];
char str[20][50], str1[50],strx[50], stry[50], ch,ch1;
int main(){
	cin>>t;
	while(t--){
			REPP(i,1,20) str[i][0]='\0';
			REPP(i,1,20)REPP(j,1,20)parent[i][j]=0;
			cin>>n>>m;
			REPP(i,1,n+1){
				str1[0] = 'a';
				while(1){
					scanf("%s",str1);
					if(str1[0]>='0'&&str1[0]<='9') break;
					strcat(str[i], str1);
				}
				w[i] = atoi(str1);
			}
			REPP(i,1,m+1){
				strx[0]='\0';
				str1[0]='a';
				while(1){
					scanf("%s",str1);
					if(str1[0]=='-') break;
					strcat(strx,str1);
				}
				ch='a';
				int k=0;
				while(scanf("%c",&ch)!=-1){
					if(ch=='\n') break;
					if(ch!=' '){
						stry[k] = ch;
						k++;
					}
				}
				stry[k] = '\0';
				REPP(i,1,n+1){if(strcmp(str[i], strx)==0){x = i; break;}}
				REPP(i,1,n+1){if(strcmp(str[i], stry)==0){y = i; break;}}
				parent[x][y]=1;
			}
			int flag=0;
			REPP(i,1,n+1){if(parent[i][i]==1)flag=1;}
			if(flag==1){cout<<"0\n";continue;}
			int u = 1<<n;
			dp[0]=0;
			REPP(i,1,u){
				REPP(j,1,n+1){
					bit[j] = ((i&(1<<(j-1)))==0)?0:1;
			}
			flag=0;
			int valbit=0;
			REPP(j,1,n+1){
				valbit=j;
				if(bit[j]==1){
					x = i - (1<<(j-1));
					if(dp[x]>=0){flag=1;break;}
				}
			}
			if(flag==0){dp[i]=-1;continue;}
			flag=0;
			REPP(j,1,n+1){
				if(bit[j]==0){
					if(parent[valbit][j]==1){ flag=1;}
				}
			}
			if(flag==1){dp[i]=-1;continue;}
			int maxi = -1;
			int days = n - __builtin_popcount (i) + 1;
			REPP(j,1,n+1){
				if(bit[j]==1){
					x = i - (1<<(j-1));
					if(dp[x]!=-1){
						maxi = max(maxi, dp[x]+days*w[j]);
					}
				}
			}
			dp[i] = maxi;		
		}
		cout<<max(0,dp[u-1])<<"\n";
	}
	return 0;
}
