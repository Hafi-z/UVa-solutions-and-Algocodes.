#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007

ll dp[401][401];
ll n,k,a[401];

int main()
{_
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    ll t=1,ca=1;
    //cin>>t;
    while(t--){///problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=945
        cin>>n>>k;
        ll s=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            s+=a[i];
        }
        ll x=0;
        ///dp[i][j] = min sum till ith grp of snakes with j resizing
        for(int i=1;i<=n;i++){
            x=max(x,a[i]);
            dp[i][0]=x*i;///base case
            for(int j=1;j<=k;j++){
                dp[i][j]=INT_MAX;
                ll mx=0;
                for(int l=i-1;l>=0;l--){
                    mx=max(mx,a[l+1]);
                    dp[i][j]=min(dp[i][j],dp[l][j-1]+mx*(i-l));
                }
            }
        }
        ll ans=dp[n][k]-s;
        cout<<ans;
    }
}

