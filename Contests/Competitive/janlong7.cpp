#include<stdio.h>
#include"iostream"
#include<set>
#include<math.h>
#include<algorithm>
using namespace std;
void ins(multiset<int> &s,int x)
{
    s.insert(x);
}
void del(multiset<int> &s,int x)
{
  s.erase(x);
}
int num(multiset<int> &s,int x)
{
  int i=0;
  multiset<int>::iterator it;
  it = s.upper_bound(x);
  while(it!=s.begin())
    {
      i++;
      it--;
    }
  return i;
}
pair<int,int> xo(multiset<int> &s,int x)
{
  multiset<int>::iterator itl,itr,it3;
  itl=s.begin();
  itr=s.end();
  itr--;
  int i,temp,bitset[20];
  for(i=0;i<19;i++)
    {
      bitset[i-1]=x%2;
      x/=2;
    }
  for(i=18;i>=0;i--)
    {
      if(bitset[i]==0)
	{
	  it3=s.lower_bound(pow(2,i));
	  if(*it3>*itr);
	  else 
	    itl=it3;
	}
      else 
	{
	  it3=s.upper_bound(pow(2,i)-1);
	  if(*it3<=*itl);
	  else 
	    {
	      it3--;
	      itr=it3;
	    }
	}
    }
  return make_pair(*itl,x^(*itl));
}
int val[600000];
int order[100];
multiset <int> s[1500000];
int main()
{
  int beg,mid,end,max,temp,i,type,j,k,l,r,m,x,pos=-1,sz=524288;
  scanf("%d",&m);
  while(m--)
    {
      scanf("%d",&type);
      switch(type)
	{
	case 0:
	  scanf("%d",&x);
	  pos++;
	  val[pos]=x;
	  j=sz-1+pos;
	  ins(s[j],x);
	  while(j>0)
	    {
	      j=(j-1)/2;
	      ins(s[j],x);
	    }
	  break;
	case 2:
	  scanf("%d",&k);
	  for(i=0;i<k;i++)
	    {
	      x=val[pos];
	      j=sz-1+pos;
	      del(s[j],x);
	      while(j>0)
		{
		  j=(j-1)/2;
		  del(s[j],x);
		}
	      pos--;
	    }
	  break;
	case 3:
	  scanf("%d",&l);
	  scanf("%d",&r);
	  scanf("%d",&x);
	  temp=0;
	  l=sz-2+l;
	  r=sz-2+l;
          if(l>r)
            {
              while((l-1)/2!=(r-1)/2)
                {
                  if(l%2==1)
                    temp+=num(s[l+1],x);
                  if(r%2==0)
                    temp+=num(s[r-1],x);
                  l=(l-1)/2;
                  r=(r-1)/2;
                }
            }
	  printf("%d\n",temp);
	  break;
	case 1:
	  scanf("%d",&l);
	  scanf("%d",&r);
	  scanf("%d",&x);
	  pair <int,int>(j,max)=xo(s[l],x);
	  pair<int,int> result;
	  l=sz-2+l;
	  r=sz-2+l;
          if(l>r)
            {
              while((l-1)/2!=(r-1)/2)
                {
                  if(l%2==1)
		    {
		      result=xo(s[l+1],x);
		      if(result.second>max)
			j=result.first;
		    }
                  if(r%2==0)
		    {
		      result=xo(s[r-1],x);
		      if(result.second>max)
			j=result.first;
		    }
		  l=(l-1)/2;
                  r=(r-1)/2;
                }
            }
	  printf("%d\n",j);
	  break;
	case 4:
	  scanf("%d",&l);
	  scanf("%d",&r);
	  scanf("%d",&k);
	  j=0;
	  l=sz-2+l;
	  r=sz-2+l;
	  order[j]=l;
	  j++;
          if(l>r)
            {
              while((l-1)/2!=(r-1)/2)
                {
                  if(l%2==1)
		    {
		      order[j]=l+1;
		      j++;
		    }
                  if(r%2==0)
		    {
		      order[j]=r-1;
		      j++;
		    }
		  l=(l-1)/2;
                  r=(r-1)/2;
                }
            }
	  beg=1;
	  end=500000;
	  


	}	
   

  return 0;
}


