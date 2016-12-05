#include<stdio.h>
#include"iostream"
#include<string.h>
using namespace std;
typedef long long ll;
#define gc getchar_unlocked
inline int getn()
{
    int n=0;
    int ch=gc();
    while( ch < '0' || ch > '9' ){ch=gc();}
    
    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=gc();
    
    return n ;
}
#define p(x) printf("data %d {%d,%d,%d,%d,%d,%d,%d,%d} \n",i,x.l1,x.l2,x.l3,x.r1,x.r2,x.r3,x.ans,x.sum);
struct interval
{
    ll ans[4][4][2];
    int freq[5];
};
typedef interval node;
int mu(char ch)
{
    if(ch=='c')
        return 0;
    else if(ch=='h')
        return 1;
    else if(ch=='e')
        return 2;
    else if(ch=='f')
        return 3;
    else return 4;
}
int findpow(int n)
{
    int temp=1;
    while(temp<n)
        temp*=2;
    return temp;
}
node val[2500000];
void calculate(ll index,char chl,char chr)
{
    ll i=mu(chl),j=mu(chr);
    if(val[index].ans[i][j][1]!=0)
        return;
    calculate(2*index+1,chl,chr);
    calculate(2*index+2,chl,chr);
    val[index].ans[i][j][1]=1;
    val[index].ans[i][j][0]=val[2*index+1].ans[i][j][0]+val[2*index+2].ans[i][j][0]+val[2*index+1].freq[i]*val[2*index+2].freq[j];
    val[index].freq[i]=val[2*index+1].freq[i]+val[2*index+2].freq[i];
    val[index].freq[j]=val[2*index+1].freq[j]+val[2*index+2].freq[j];
    return ;
}
node mergel (node l ,node r,ll index,char chl,char chr)
{
    // ll temp;
    node result;
    calculate(index,chl,chr);
    int i=mu(chl),j=mu(chr);
    result.freq[i]=l.freq[i]+val[index].freq[i];
    result.freq[j]=l.freq[j]+val[index].freq[j];
    result.ans[i][j][0]=l.ans[i][j][0]+val[index].ans[i][j][0]+l.freq[i]*val[index].freq[j];
    /*   if(index==5)
     {
     printf("check");
     printf(" %d %d\n",l.freq[i],r.freq[j]);
     }*/
    return result;
}
node merger (node l ,node r,ll index,char chl,char chr)
{
    // ll temp;
    node result;
    calculate(index,chl,chr);
    int i=mu(chl),j=mu(chr);
    result.freq[i]=val[index].freq[i]+r.freq[i];
    result.freq[j]=val[index].freq[j]+r.freq[j];
    result.ans[i][j][0]=val[index].ans[i][j][0]+r.ans[i][j][0]+val[index].freq[i]*r.freq[j];
    /*   if(index==5)
     {
     printf("check");
     printf(" %d %d\n",l.freq[i],r.freq[j]);
     }*/
    return result;
}

node assign(char ch)
{
    node x;
    int i,j;
    for(i=0;i<4;i++)
        x.freq[i]=0;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            x.ans[i][j][0]=0;
            x.ans[i][j][1]=1;
        }
    x.freq[mu(ch)]++;
    return x;
}
typedef struct interval node;
int main()
{
    int i,sz,n,m,v,q,q1,q2,s,t;
    node left,right;
    char ch,str[1200000],chl,chr;
    scanf("%s",str);
    n=strlen(str);
    //   n=1000000;
    sz=findpow(n);
    for(i=sz-1;i<sz-1+n;i++)
    {
        ch=str[i-sz+1];
        //      ch='c';
        //  val[i]=assign(ch);
        for(s=0;s<4;s++)
            val[i].freq[s]=0;
        for(s=0;s<4;s++)
            for(t=0;t<4;t++)
            {
                val[i].ans[s][t][0]=0;
                val[i].ans[s][t][1]=1;
            }
        val[i].freq[mu(ch)]++;
        
        //    val[i].freq[mu(ch)]++;
        //    p(val[i]);
    }
    for(;i<2*sz-1;i++)
    {
        //     val[i]=assign('b');
        for(s=0;s<4;s++)
            for(t=0;t<4;t++)
                val[i].ans[s][t][1]=1;
    }
    //  for(i=sz-2;i>=0;i--)
    //   {
    //    val[i]=merge(val[2*i+1],val[2*i+2]);
    //   p(val[i]);
    //   }
    //  printf("%lld %lld\n",val[0].ans[mu('c')][mu('f')][0],val[0].ans[mu('c')][mu('f')][1]);
    
    q=getn();
    for(i=0;i<q;i++)
    {
        scanf("%c",&chl);
        scanf("%c",&ch);
        scanf("%c",&chr);
        q1=getn();
        q2=getn();
        //  scanf("%d%d",&q1,&q2);
        left=assign(str[q1-1]);
        right=assign(str[q2-1]);
        //   printf("%d\n",right.freq[mu(chr)]);
        q1=sz-2+q1;
        q2=sz-2+q2;
        if(q2>q1)
        {
            while((q1-1)/2!=(q2-1)/2)
            {
                if(q1%2==1)
                    left=mergel(left,val[q1+1],q1+1,chl,chr);
                if(q2%2==0)
                    right=merger(val[q2-1],right,q2-1,chl,chr);
                q1=(q1-1)/2;
                q2=(q2-1)/2;
            }
            //	  left=merge(left,right);
        }
        //     printf("%c %c\n",chl,chr);
        printf("%lld\n",left.ans[mu(chl)][mu(chr)][0]+right.ans[mu(chl)][mu(chr)][0]+left.freq[mu(chl)]*right.freq[mu(chr)]);
    }
    return 0;
}

