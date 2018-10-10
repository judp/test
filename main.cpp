#include<cstdio>

void mv(int f,int x,int y);
void exchange(int x,int y);

constexpr int maxn =100001;
int d[2][maxn];
bool flag;
int m,n;
int main()
{
    int kase=0;
    while(scanf("%d%d",&n,&m)==2)
    {
        flag=0;
        for(int i=1; i<=n; ++i)
        {
            d[0][i]=i+1;
            d[1][i]=i-1;
        }
        d[0][n]=0;
        d[0][0]=1;
        d[1][0]=n;

        int cmd,x,y;
        for(int i=0; i<m; ++i)
        {
            scanf("%d",&cmd);
            --cmd;
            if(cmd!=3)
                scanf("%d%d",&x,&y);
            if(cmd==0||cmd==1)
                mv(flag^cmd,x,y);
            else if(cmd==2)
                exchange(x,y);
            else if(cmd==3)
                flag=!flag;
        }
        long long sum=0;
        for(int i=0,cnt=1; d[flag][i]; i=d[flag][i],cnt++)
        {
            if(cnt%2)
                sum+=d[flag][i];
            //printf("%d   ",d[flag][i]);
        }
        printf("Case %d: %lld\n",++kase,sum);
        //putchar('\n');
    }
}

void mv(int f,int x,int y)
{
    if(!d[f][x] || d[f][x]!=d[!f][y])
    {
        d[f][d[!f][x]]=d[f][x];

        if(d[f][x])
            d[!f][d[f][x]]=d[!f][x];
        else
            d[!f][0]=d[!f][x];

        if(d[!f][y])
            d[f][d[!f][y]]=x;
        else
            d[f][0]=x;

        d[!f][x]=d[!f][y];

        d[f][x]=y;
        d[!f][y]=x;
    }
}
void exchange(int x,int y)
{


    int r=d[flag][y],l=d[!flag][y];

    if(l)
        d[flag][l]=x;
    else
        d[flag][0]=x;

    if(r)
        d[!flag][r]=x;
    else
        d[!flag][0]=x;

    if(d[!flag][x])
        d[flag][d[!flag][x]]=y;
    else
        d[flag][0]=y;

    if(d[flag][x])
        d[!flag][d[flag][x]]=y;
    else
        d[!flag][0]=y;

    d[flag][y]=d[flag][x];
    d[!flag][y]=d[!flag][x];

    d[flag][x]=r;
    d[!flag][x]=l;
}










