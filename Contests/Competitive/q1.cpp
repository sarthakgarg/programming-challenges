#include<bits/stdc++.h>
//#include<stdio.h>
//#include"iostream"
using namespace std;
typedef long long ll;
void convert(int i,char str[])
{
  switch(i)
    {
    case 0: strcpy(str,"zero");
      break;
    case 1:  strcpy(str,"one");
break;
    case 2:strcpy(str,"two");
break;
    case 3:strcpy(str,"three");
break;
    case 4:strcpy(str,"four");
break;
    case 5:strcpy(str,"five");
break;
    case 6:strcpy(str,"six");
break;
    case 7:strcpy(str,"seven");
break;
    case 8:strcpy(str,"eight");
break;
    case 9:strcpy(str,"nine");
break;
    }
  return;
}
void convert1(int i,char str[])
{
  switch(i)
    {
    case 0: strcpy(str,"zero");
      break;
    case 1:  strcpy(str,"one");
break;
    case 2:strcpy(str,"twen");
break;
    case 3:strcpy(str,"thir");
break;
    case 4:strcpy(str,"for");
break;
    case 5:strcpy(str,"fif");
break;
    case 6:strcpy(str,"six");
break;
    case 7:strcpy(str,"seven");
break;
    case 8:strcpy(str,"eigh");
break;
    case 9:strcpy(str,"nine");
break;
    }
  return;
}

int main()
{
  char str[20];
  int t,i,j,k;
  // for(t=0;t<100;t++)
  // {
    scanf("%d",&t);
  if(t==0)
    printf("zero\n");
  else if(t<10)
    {
      convert(t,str);
      printf("%s\n",str);
    }
  else if(t==10)
    printf("ten\n");
  else if(t==11)
    printf("eleven\n");
  else if(t==12)
    printf("tweleve\n");
  else if(t==14)
    printf("fourteen\n");
  else if(t<20)
    {
      convert1(t-10,str);
      printf("%steen\n",str);
    }
  else 
    {
      i=t%10;
      j=t/10;
      convert1(j,str);
      printf("%sty",str);
      if(i)
	{
	  convert(i,str);
	  printf("-%s\n",str);
	}
    else 
      printf("\n");
    }
  //  }
  return 0;
}
