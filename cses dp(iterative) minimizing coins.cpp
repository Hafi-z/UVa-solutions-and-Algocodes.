#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007

ll n,x,dp[1000005],a[105];

int main()
{_
    ll t=1,ca=1;
    //cin>>t;
    while(t--){///problem: https://cses.fi/problemset/task/1634
        cin>>n>>x;
        //memset(dp,INT_MAX,sizeof dp);
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=x;i++){
            //for(int j=0;j<=n;j++){
                dp[i]=1e9;
            //}
        }
        dp[0]=0;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=n;j++){
                if(i-a[j]>=0)dp[i]=min(dp[i],dp[i-a[j]]+1);
                //debug(dp[i][j])
            }
        }
        //debug(dp[1][2])
        if(dp[x]!=1e9)cout<<dp[x];
        else cout<<-1;
    }
}

