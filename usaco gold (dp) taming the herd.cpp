#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007
#define mod2 998244353
#define inf LLONG_MAX



int main()
{_
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    ll t=1,ca=1;
    //cin>>t;
    while(t--){///problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=815
        ll n;
        cin>>n;
        ll a[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        vector<vector<ll>>dp(n+1,vector<ll>(n+1,inf));
        ///definition of dp[i][j]=min cost till position j using i breakouts
        ll cnt=0;
        for(int i=0;i<n;i++)cnt+=(i!=a[i+1]),dp[1][i+1]=cnt;
        cout<<dp[1][n]<<endl;

        for(int i=1;i<=n;i++)dp[i][0]=0;

        for(int i=2;i<=n;i++){
            for(int j=1;j<=n;j++){
                ///placing a breakout at k and we
                ///are currently at position j, so
                ///dp[i][j]=(cost of using i-1 breakout till position k-1) + (cost from k to j)
                for(int k=i;k<=j;k++){
                    cnt=0;
                    for(int l=k,m=0;l<=j;l++,m++)cnt+=(m!=a[l]);
                    dp[i][j]=min(dp[i][j],dp[i-1][k-1]+cnt);
                }
                //cout<<dp[i][j]<<" ";
            }//cout<<endl;
            //debug(12)
            cout<<dp[i][n]<<endl;
        }
    }
}

