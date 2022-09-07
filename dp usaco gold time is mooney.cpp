#include<bits/stdc++.h>
using namespace std;

#define ll int
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007

ll n,m,c,cnt,cnt2=-1,z2,a[2005],vis[2005],ans[2005],ans2;
vector<ll>adj[2005];

vector<vector<ll>>dp(1005,vector<ll>(1005,-1));

int main()
{_
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    ll t=1,ca=1;
    //cin>>t;
    while(t--){///problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=993
        /// dp[i][j] = the max money that Bessie can make on day i if she reaches in city j
        cin>>n>>m>>c;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=m;i++){
            ll b,d;
            cin>>b>>d;
            adj[b].push_back(d);
        }
        ///max day can be 1000 at most, else earnings will be negative
        dp[0][1]=0;///initially at day 0, earning is 0
        for(int i=0;i<=1000;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][j]!=-1){
                    for(auto k:adj[j]){
                        dp[i+1][k]=max(dp[i+1][k],dp[i][j]+a[k]);
                    }
                }
            }
            ans2=max(ans2,dp[i][1]-c*i*i);
        }
        cout<<ans2<<endl;
    }
}

