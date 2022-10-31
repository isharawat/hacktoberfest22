#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[20][2][11][2];
ll solve(string x,ll i,ll j,ll k,ll l);
void init()
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<11;k++)
            {
                for(int l=0;l<2;l++)
                {
                    dp[i][j][k][l]=-1;
                }
            }
        }
    }
}
int main()
{
    ll a,b;
    cin>>a>>b;
    string s,t;
 
    t=to_string(b);
    init();
     b=solve(t,0,0,10,1);
     if(a==0)
     {
         cout<<b;
         return 0;
     }
     s=to_string(a-1);
    init();
     a=solve(s,0,0,10,1);
 
    cout<<b-a;
}
ll solve(string x,ll i,ll j,ll k,ll l)
{
    if(i==x.size())
    {
        return 1;
    }
    if(dp[i][j][k][l]!=-1)
    {
        return dp[i][j][k][l];
    }
    int limit=9;
    if(j==0)
    {
        limit=x[i]-'0';
    }
    ll sum=0;
    for(int y=0;y<=limit;y++)
    {
        if(j||y<limit)
        {
           if(y!=k||(l&&y==0))
           {
               if(!y&&l)
               {
                   sum+=solve(x,i+1,1,y,1);
               }
               else
               {
                   sum+=solve(x,i+1,1,y,0);
               }
 
           }
        }
        else
        {
           if(y!=k||(l&&y==0))
           {
                if(!y&&l)
               {
                   sum+=solve(x,i+1,0,y,1);
               }
               else
               {
                   sum+=solve(x,i+1,0,y,0);
               }
           }
        }
    }
    return dp[i][j][k][l]=sum;
}
