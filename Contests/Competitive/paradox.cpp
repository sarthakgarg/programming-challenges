#include<stdio.h>
#include"iostream"
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
int main()
{
  int n,i,j,k;
  char str[10];
  scanf("%d",&n);
  while(n)
    {
      queue <int> list;
      int truth[105]={0},visited[105]={0};
      int flag=1;
      pp inp[105];
      for(i=0;i<n;i++)
	{
	  scanf("%d %s",&inp[i].first,str);
	  inp[i].first--;
	  if(str[0]=='t')
	    inp[i].second=1;
	  else inp[i].second=-1;
	}
      for(i=0;i<n;i++)
	{
	  if(visited[i]==1)
	    continue;
	  truth[i]=1;
	  list.push(i);
	  k=i;
	  while(1)
	    {
	      j=inp[k].first;
	      list.push(j);
	      if(visited[j]==1)
		break;
	      if(truth[j]==0)
		truth[j]=(inp[k].second)*truth[k];
	      else
		{
		  if(truth[j]!=(inp[k].second)*truth[k])
		    {
		      flag=0;
		      break;
		    }
		  else 
		    break;
		}
	      k=j;
	    }
	  if(flag==0)
	    {
	      printf("PARADOX\n");
	      break;
	    }
	  while(!list.empty())
	    {
	      visited[list.front()]=1;
	      list.pop();
	    }
	}
      if(flag==1)
	printf("NOT PARADOX\n");
      scanf("%d",&n);
    }   
  return 0;
}





