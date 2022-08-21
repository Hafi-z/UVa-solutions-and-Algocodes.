#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007

ll bigmod(ll b,ll p)
{
    ll an=1;b%=mod;
    while(p>0){
        if(p&1)an=an*b%mod;
        b=b*b%mod;
        p>>=1;
    }
    return an;
    ///BINARY EXPONENTATION///
    ///TAKEN FROM "e-maxx"///
}

ll dp[100005][505],n,a[505];

ll solve(ll sum,ll idx)
{
    if(sum==0)return 1;
    if(idx<1)return 0;

    if(dp[sum][idx]!=-1)return dp[sum][idx];

    ll ans=0;
    ans|=solve(sum,idx-1);
    if(sum-a[idx]>=0)ans|=solve(sum-a[idx],idx-1);

    return dp[sum][idx]=ans;
}

int main()
{_
    ll t=1,ca=1;
    //cin>>t;
    while(t--){///problem: https://cses.fi/problemset/task/1093
        cin>>n;

        //memset(dp,-1,sizeof dp);

        ll x=(n*(n+1))/2;
        if(x%2!=0){
            cout<<0;return 0;
        }
        x/=2;
        for(int j=0;j<=n;j++)dp[0][j]=1;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i][j-1];
                if(i-j>=0)dp[i][j]=(dp[i-j][j-1]+dp[i][j])%mod;
            }
        }
        cout<<(dp[x][n]*bigmod(2,mod-2))%mod;
    }
}

