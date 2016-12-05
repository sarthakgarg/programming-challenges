#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define trv(i,n) for(i=0;i<n;i++)
int main()
{
  ii pair1;
  pair1 = ii(5,6);
  printf("%d %d\n ",pair1.first,pair1.second);
  int i;
  vector <int> v(5,10) ;
  vector<int>::iterator it;
  for(it=v.begin();it!=v.end();it++)
    printf("%d\n",*it);
  return 0;
}
