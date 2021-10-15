#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007

ll n,h[100005],dp[100005];

int main()
{_
    ll t=1,ca=1;
    //cin>>t;
    while(t--){///https://atcoder.jp/contests/dp/tasks/dp_a
        cin>>n;
        for(int i=1;i<=n;i++)cin>>h[i];
        dp[1]=0;
        dp[2]=abs(h[2]-h[1]);
        for(int i=3;i<=n;i++){
            dp[i]=min(dp[i-1]+abs(h[i-1]-h[i]),dp[i-2]+abs(h[i-2]-h[i]));

        }
        cout<<dp[n]<<endl;
    }
}

