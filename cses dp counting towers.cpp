#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007



int main()
{_
//    freopen("angry.in", "r", stdin);
//    freopen("angry.out", "w", stdout);
    ll t=1,ca=1;
    cin>>t;
    while(t--){///tutorial: https://dp-book.com/Dynamic_Programming.pdf ///page 13.
        ll n;
        cin>>n;
        ll dp[n+1][2];
        ///0 means separated blockes on i-th row
        ///1 means joined block on i-th row
        dp[1][0]=1;
        dp[1][1]=1;
        ///base cases above
        for(int i=2;i<=n;i++){
            dp[i][1]=(dp[i-1][1]+dp[i-1][1]+dp[i-1][0])%mod;
            dp[i][0]=(4ll*dp[i-1][0]+dp[i-1][1])%mod;
        }
        ll ans=(dp[n][0]+dp[n][1])%mod;
        cout<<ans<<endl;
    }
}

