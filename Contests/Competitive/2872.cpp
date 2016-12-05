#include<stdio.h>
#include"iostream"
#include<math.h>
#define eps 0.0000001
typedef double d;
int compare(d a,d b)
{
  if(a<b+eps&&a>b-eps)
    return 0;
  if(a<b-eps)
    return -1;
  else return 1;
}
typedef long long ll;
int main()
{
  d r,x1,y1,x2,y2,dist;
  ll i,j,count,sum;
  scanf("%lf%lf%lf%lf%lf",&r,&x1,&y1,&x2,&y2);
  dist=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
  count=0;
  while(compare(dist,2*r)==1)
    {
      count++;
      dist-=2*r;
    }
  if(compare(dist,0)!=0)
    count++;
  printf("%I64d\n",count);
  return 0;
}
