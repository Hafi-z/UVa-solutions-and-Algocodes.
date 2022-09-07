#include<bits/stdc++.h>
using namespace std;

#define ll int
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007

ll dp[10005];

int main()
{_
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    ll t=1,ca=1;
    //cin>>t;
    while(t--){///problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=863
        ll n,k;
        cin>>n>>k;
        ll x=0;
        ll a[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i];
            //if(i<=k)x=max(x,a[i]);
        }
        for(int i=1;i<=k;i++){
            x=max(x,a[i]);
            dp[i]=x*i;
        }
        for(int i=k+1;i<=n;i++){
            x=0;
            for(int j=i,l=1;l<=k;l++,j--){
                x=max(x,a[j]);
                dp[i]=max(dp[i],x*l+dp[j-1]);
            }
            //debug(dp[i])
        }
        cout<<dp[n];
    }
}

