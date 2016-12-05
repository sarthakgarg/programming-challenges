#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll temp,a,b,c=0,i,j,n,arr[10006]={0};
int main()
{
  scanf("%lld%lld%lld",&a,&b,&n);
  for(i=1;i*i<=b;i++)
    {
      if(a%i==0)
	temp=0;
      else temp = i-a%i;
      for(j=temp;j<=b-a;j+=i)
	{
	  arr[j]++;
	  if(i!=(a+j)/i&&((a+j)/i)*((a+j)/i)>b)
	    arr[j]++;
	}
    }
  for(i=0;i<=b-a;i++)
    {
       if(arr[i]==n)
	c++;
    }
  printf("%lld\n",c);
  return 0;
}
