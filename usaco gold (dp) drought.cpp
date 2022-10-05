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
//    freopen("taming.in", "r", stdin);
//    freopen("taming.out", "w", stdout);
    ll t=1,ca=1;
    //cin>>t;
    while(t--){///problem: http://usaco.org/index.php?page=viewproblem2&cpid=1185
        ///tutorial: http://usaco.org/current/data/sol_prob1_gold_jan22.html
        ll n;
        cin>>n;
        ll a[n+1],ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ll x=*min_element(a+1,a+n+1);

        for(int i=0;i<=x;i++){
            vector<vector<ll>>dp(n+1,vector<ll>(1000+1,0));
            vector<ll>pre(1000+1);

            for(int j=0;j<=a[1];j++)dp[1][j]=1,pre[j]=j+1;
            for(int j=a[1]+1;j<=1000;j++)pre[j]=pre[j-1];

            for(int j=2;j<=n;j++){
                for(int k=0;k<=a[j];k++){
                    dp[j][k]=pre[a[j]-k];
                }
                pre[0]=dp[j][0];
                for(int k=1;k<=1000;k++)pre[k]=(pre[k-1]+dp[j][k])%mod;
            }
            ans=(ans+dp[n][0])%mod;
            if(n%2==0)break;
            for(int j=1;j<=n;j++)a[j]--;
        }
        cout<<ans<<endl;
    }
}

