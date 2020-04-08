#include <bits/stdc++.h>
using namespace std;
const int N=1e3+3;
int n,m,k,par[N][N*10],ans[N*300];
pair<int,int> idx[N*300];
pair<int,pair<int,int> > p[N*300];
int findpar (int x,int idx)
{
    if (par[x][idx]==x)
        return x;
    return par[x][idx]=findpar(par[x][idx],idx);
}
void unun(int n1,int n2,int idx)
{
    int x1= findpar(n1,idx);
    int x2= findpar(n2,idx);
    par[x1][idx]=x2;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        p[i]= {c,{a,b}};
        idx[i]={c,i};
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<k;j++)
            par[i][j]=i;
    }
    sort(p,p+m);
    sort(idx,idx+m);
    reverse(p,p+m);
    reverse(idx,idx+m);
    for (int i=0;i<m;i++)
    {
        int a= p[i].second.first;
        int b= p[i].second.second;
        int low=0,high=k-1,mid,ans1=k;
        while (low<=high)
        {
            mid= (low+high)/2;
            int x1=findpar(a,mid);
            int x2=findpar(b,mid);
            if (x1==x2)
            {
                low=mid+1;
            }
            else
            {
                ans1=mid;
                high=mid-1;
            }
        }
        if (ans1!=k)
        {
            ans[idx[i].second]=ans1+1;
            unun(a,b,ans1);
        }
    }
    for (int i=0;i<m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
