#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007

ll n,dp[1000005];

int main()
{_
    ll t=1,ca=1;
    //cin>>t;
    while(t--){///problem: https://cses.fi/problemset/task/1633
        cin>>n;
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=6;j++){
                if(i-j>=0)dp[i]=(dp[i]+dp[i-j])%mod;
            }
        }
        cout<<dp[n];
    }
}
