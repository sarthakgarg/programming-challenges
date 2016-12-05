#include<stdio.h>
#include"iostream"
#include<math.h>
#include<vector>
#include<algorithm>
#define EPS 0.000000001
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,a,b) for(int i=a;i<b;i++)
#define X first
#define Y second
#define pb push_back
#define	foreach( gg,itit )	for( auto itit=gg.begin();itit!=gg.end();itit++ )
using namespace std;
typedef long long ll;
typedef pair<float,float> dd;
typedef pair<float,dd> point;
point blue[100005];
dd reds[100005];
dd redf[100005];
int cb,crs,crf;
int tb,trs,trf;
int comp(float x, float y){
	if(x-y<EPS&&x-y>-EPS) return 0;
	if(x>y) return 1;
	return -1;
}
typedef struct noder
{
	float val;
	int freq;
	int count;
	noder* left;
	noder* right;
	noder* parent;
}node;
node* root=NULL;
int isnull(node* p){
	if (p->val==2) return 1;
	else return 0;
}
void init(node* p){    //declares a node as leaf. 
	p->val = 2;
	p->freq = 0;
	p->count = 0;
	p->left=NULL;
	p->right=NULL;
	p->parent=NULL;
}
node* find(float x){ 
	node* head=root;
	while(!isnull(head)){
		int sig = comp(x,head->val);
		if(sig==0)return head;
		else if(sig==1) head=head->right;
		else head=head->left;
	}
	return head;
}
void upd(node* p, int val){
	while(p!=root){
		p->count = p->count + val;
		p=p->parent;
	}
	p->count = p->count + val;
}
void insert(float x, node* p){ 
	if(isnull(p)){
		p->val=x;
		p->count=1;
		p->freq=1;
		p->left = (node*) calloc(1,sizeof(node));
		init(p->left);
		p->right = (node*) calloc(1,sizeof(node));
		init(p->right);
		p->left->parent = p;
		p->right->parent = p;
	}
	else {p->count++;p->freq++;}
	if(p!=root) upd(p->parent, 1);
	return;
}
void del(node* p){
	p->count--;
	p->freq--;
	if(p!=root) upd(p->parent,-1);
}
int cleq(node* p, float x){ 
	if(isnull(p)) return 0;
	int sig = comp(x, p->val);
	if(sig==-1) return cleq(p->left, x);
	if(sig==0) return (p->freq+cleq(p->left, x));
	return (p->freq+p->left->count+cleq(p->right, x));
}
int clq(node* p, float x){ 
	if(isnull(p)) return 0;
	int sig = comp(x, p->val);
	if(sig==-1) return clq(p->left, x);
	if(sig==0) return clq(p->left, x);
	return (p->freq+p->left->count+clq(p->right, x));	
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	root = (node*) calloc(1,sizeof(node));
	init(root);
	int n;
	float x,y,z;
	ll ans=0;
	cin>>n;
	REP(i,n){
		cin>>x>>y>>z;
		if(x>y) swap(x,y);
		blue[cb] = point(z,dd(x,y));
		cb++;
	}
	sort(blue,blue + cb);
	REP(i,n){
		cin>>x>>y>>z;
		if(x>y) swap(x,y);
		reds[crs] = dd(x,z);
		redf[crf] = dd(y,z);
		crs++;
		crf++;
	}
	sort(redf,redf+crf);
	sort(reds,reds+crs); 
	for(tb=0;tb<cb;tb++){
		x = blue[tb].X;
		y = blue[tb].Y.X;
		z = blue[tb].Y.Y;
		while(trs<crs&&comp(reds[trs].X,x)<=0){
			node* temp = find(reds[trs].Y);
			insert(reds[trs].Y,temp);
			trs++;
		}
		while(trf<crf&&comp(redf[trf].X,x)<0){
			node* temp = find(redf[trf].Y);
			del(temp);
			trf++;
		}
		ans+=(cleq(root,z)-clq(root,y));
	}
	cout<<ans<<"\n";
	return 0;
}