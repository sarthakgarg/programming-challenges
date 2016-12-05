#include<stdio.h>
#include"iostream"
#include<math.h>
#define EPS 0.00000001
using namespace std;
int comp(double x, double y){
	if(x-y<EPS&&x-y>-EPS) return 0;
	if(x>y) return 1;
	return -1;
}
typedef struct noder
{
	double val;
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

node* find(double x){   // returns the pointer to the node corresponding to x, if x is not found then it returns the NULL node, where the value x can be inserted. 
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

void insert(double x, node* p){ //Inserts an element in bst, assigns the root node if it is null. Correctly calculates the values of all the parameters
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

void traversal(node* p){
	if(!isnull(p)){
		traversal(p->left);
		printf(" (%.2lf, %d)",p->val,p->count);
		traversal(p->right);
	}
}

void del(node* p){
	p->count--;
	p->freq--;
	if(p!=root) upd(p->parent,-1);
}

int cleq(node* p, double x){ //counts the number of elements less than or equal to x in the subtree headed by p
	if(isnull(p)) return 0;
	int sig = comp(x, p->val);
	if(sig==-1) return cleq(p->left, x);
	if(sig==0) return (p->freq+cleq(p->left, x));
	return (p->freq+p->left->count+cleq(p->right, x));
}

int clq(node* p, double x){ // counts the number of elements less than x in the subtree headed by p
	if(isnull(p)) return 0;
	int sig = comp(x, p->val);
	if(sig==-1) return clq(p->left, x);
	if(sig==0) return clq(p->left, x);
	return (p->freq+p->left->count+clq(p->right, x));	
}

int main(){
	root = (node*) calloc(1,sizeof(node));
	init(root);
	int y;
	double x,z;
	while(1){
		cin>>y;
		if(y==5) break;
		else if(y==2){traversal(root);cout<<"\ntraversed\n";}
		else{
			cin>>x;
			if(y==1){
				node* temp = find(x);
				cout<<"\nfound position\n";
				insert(x,temp);
				cout<<"\ninserted\n";
			}
			if(y==3){
				node* temp = find(x);
				cout<<"\nfound position\n";
				del(temp);
				cout<<"\ndeleted\n";
			}
			if(y==4){
				cin>>z;
				cout<<cleq(root,z)-clq(root,x)<<"\n";
				cout<<"counted\n";
			}
		}
	}         //tested the insert and the find functions. They are working fine upto this point. 
			  // tested the delete and the count functions too. everything working fine till now. 			
	return 0;
}