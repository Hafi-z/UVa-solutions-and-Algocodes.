#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007

ll dp[1000005],n,m,a[1000005];

ll solve(ll i)
{
    if(i<1)return 1;
    if(dp[i]!=-1)return dp[i];

    ll ans=0;
    for(int j=1;j<=n;j++){
        if(i>=a[j])ans=(ans+solve(i-a[j]))%mod;
    }
    return dp[i]=ans;
}

int main()
{_
    ll t=1,ca=1;
    //cin>>t;
    while(t--){///problem: https://cses.fi/problemset/task/1635
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            dp[a[i]]=1;
        }
//        memset(dp,-1,sizeof dp);
//        cout<<solve(m)<<endl;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                ll x=i-a[j];
                if(x>=1)dp[i]=(dp[i]+dp[x])%mod;
            }
        }
        cout<<dp[m]<<endl;
    }
}

