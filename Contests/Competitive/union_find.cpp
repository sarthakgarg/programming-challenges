int fin(int i){
	if(parent[i]==i) return i;
	else{
		int j=fin(parent[i]);
		parent[i]=j;
		return j;
	}
}
void uni(int i,int j){
	int k,l;
	k=fin(i);
	l=fin(j);
	if(size[k]<size[l]){
		parent[k]=l;
		size[l]+=size[k];
		size[k]=0;
	}
	else{
		parent[l]=k;
		size[k]+=size[l];
		size[l]=0;
	}
}
