#include<stdio.h>
#include<map>
#include<algorithm>
#include"iostream"
map<int,int> m;
map<int,int>::iterator it1,it2;
int start,arr[10008],n,i,j,k,maxl,pos,t,count=0;
using namespace std ;
typedef long long ll;
int main()
{
  scanf("%d",&t);
  while(t--)
    {
      scanf("%d",&n);
      for(i=0;i<n;i++)
	{
	  scanf("%d",&arr[i]);	 
	  it=m.lower_bound(m.begin(),m.end(),arr[i]);
	  if(it==m.begin())
	    start=i;
	  else if(it==m.end())
	    {
	      it--;
	      m.insert(make_pair(arr[i],it->second));
	      count++;
	    }
	  else
	    {
	      it--;
	      start=it->second;
	      it++;
	      m.erase(it);
	      m.insert(make_pair(arr[i],start));
	    }
	}






}
 
