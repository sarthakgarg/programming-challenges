#include <stdio.h>
#include <string.h>
int ord[200],mx=-1,w[200],ans;
char seq[20];
int max(int a, int b){
   return (a>b)?a:b;
}
/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int l, int r)
{
   int i;
   if (l == r){
     printf("%s\n", a);
     ans=0;
     for(int pt=0;pt<6;pt++) {ord[a[pt]]=pt;ans+=(pt+1)*w[a[pt]];}
      if(/*ord['f']<ord['e']&&ord['f']<ord['d']&&ord['a']<ord['c']&&ord['e']<ord['c']&&ord['b']<ord['d']&&ord['d']<ord['c']&&ord['d']<ord['a']*/ord['f']<ord['e']&&ord['e']<ord['d'])
        if(mx<ans){
          mx=ans;
          strcpy(seq,a);
        }
   }
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}
 
/* Driver program to test above functions */
int main()
{
    w['a']=1;
    w['b']=5;
    w['c']=2;
    w['d']=7;
    w['e']=8;
    w['f']=3;
    char str[] = "abcdef";
    int n = strlen(str);
    permute(str, 0, n-1);
    printf("%d\n",mx);
    printf("%s\n",seq);
    return 0;
}