#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007

ll dp[100005][105],n,m,a[100005];

ll solve(ll i,ll prev)
{
    //debug2(i,prev)
    if(i<1)return 1;
    if(dp[i][prev]!=-1)return dp[i][prev];

    ll ans=0;
    if(a[i]!=0){
        if(prev==0||abs(prev-a[i])<=1){
            ans=(ans+solve(i-1,a[i]))%mod;
        }
    }
    else{
        if(prev==0){
            for(int j=1;j<=m;j++){
                ans=(ans+solve(i-1,j))%mod;
            }
        }
        else{
            for(ll j=max(1ll,prev-1);j<=min(m,prev+1);j++){
                ans=(ans+solve(i-1,j))%mod;
            }
        }
    }
    return dp[i][prev]=ans;
}

int main()
{_
    ll t=1,ca=1;
    //cin>>t;
    while(t--){///problem: https://cses.fi/problemset/task/1746/
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
//        memset(dp,-1,sizeof dp);
//        cout<<solve(n,0)<<endl;

        for(int i=1;i<=n;i++){
            if(i==1){
                if(a[i]!=0)dp[i][a[i]]=1;
                else{
                    for(int j=1;j<=m;j++)dp[i][j]=1;
                }
            }
            else if(a[i]!=0){
                dp[i][a[i]]=(dp[i-1][a[i]-1]+dp[i-1][a[i]]+dp[i-1][a[i]+1])%mod;
            }
            else{
                for(int j=1;j<=m;j++){
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%mod;
                }
            }
        }
        ll ans=0;
        if(a[n]==0){
            for(int i=1;i<=m;i++)ans=(ans+dp[n][i])%mod;
        }
        else ans=dp[n][a[n]];
        cout<<ans<<endl;
    }
}

