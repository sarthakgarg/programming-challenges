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
const int mod = 1e9+7;
int n,x,y,s,t,m,arr[400005],ans[40],lmax[400005], rmax[400005], start; 
bool bit[40];
typedef struct noder
{
	bool val;
	int posit;
	noder* left;
	noder* right;
}node;
#define gc getchar_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

node* root=NULL;
node* st;
void findbit(int x){
	REP(i,31){
		bit[i] = ((x&(1<<i))==0)?false:true;
	}
}
void insert(int x, node* p, int pos){
	findbit(x);
	for(int i=30;i>=0;i--){
		p->val = bit[i];		
		if(i>=1&&bit[i-1]==false){
			if(p->left==NULL){
				p->left = (node*) calloc(1,sizeof(node));
				p->left->left=NULL;
				p->left->right=NULL;
			}
			p = p->left;
		}
		else if(i>=1&&bit[i-1]==true){
			if(p->right==NULL){
				p->right = (node*) calloc(1,sizeof(node));
				p->right->left=NULL;
				p->right->right=NULL;
			}
			p = p->right;
		}
		else p->posit = pos;
	}
}
int find(int x, node* p){
	int re;
	int flag=0;
	findbit(x);
	for(int i= 30;i>=0;i--){
		if(i>=1){
			if(bit[i-1]==false){
				if(p->right==NULL)p = p->left;
				else p = p->right;
			}
			else{
				if(p->left==NULL)p = p->right;
				else p = p->left;
			}
		}
		else re = p->posit;
	}
	return re;
}
int main(){
	root = (node*) calloc(1,sizeof(node));
	root->left=NULL;
	root->right=NULL;
	scanint(n);
	REPP(i,1,n+1){
		scanint(y);
		x = x^y;
		arr[i] = x;
	}
	insert(arr[0], root, 0);
	int mx=-1,mxa=-1;
	REPP(i,1,n+1){
		int j = find(arr[i], root);
		lmax[i] = arr[i]^arr[j];
		mx = max(mx, lmax[i]);
		lmax[i] = mx;
		insert(arr[i], root, i);
		if(j>=1)mxa = max(mxa, lmax[j]+(arr[i]^arr[j]));
	}
	printf("%d\n",mxa);
	return 0;
}