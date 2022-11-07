#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007
#define mod2 998244353
#define inf LLONG_MAX

ll n,m,k;
ll dp[1000005];
ll dp2[1000005];
ll pre[1000005];

ll bigmod(ll b,ll p)
{
    ll an=1;b%=mod;
    while(p>0){
        if(p&1)an=an*b%mod;
        b=b*b%mod;
        p>>=1;
    }
    return an;
    ///BINARY EXPONENTATION///
    ///TAKEN FROM "e-maxx"///
}

int main()
{_
    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);
    ll t=1,ca=1;
    //cin>>t;
    while(t--){///http://www.usaco.org/index.php?page=viewproblem2&cpid=791
        ///tutorial: adnan toky
        cin>>n>>m>>k;
        ll x=m;
        dp[0]=1;
        pre[0]=1;
        ///first part
        ///subproblem: calculating number of ways with m coloring till nth index without k consecutive identical color
        ///standing at ith position, dp[i] = dp[i-1]+...+dp[i-k+1])*(m-1) ///mane last 1 ta same color nie, 2 ta nie, ..., k-1 ta nie total combination
        for(int i=1;i<=k-1;i++){
            dp[i]=x;
            x=(x*m)%mod;
            pre[i]=(pre[i-1]+dp[i])%mod;
        }
        for(int i=k;i<=n;i++){
            x=pre[i-1]-pre[i-k];
            //x=(x+mod)%mod;
            x=(x*(m-1))%mod;
            dp[i]=x;
            pre[i]=(pre[i-1]+dp[i])%mod;
        }
        ll ans=(m*bigmod(m,n-k))%mod;

        for(int i=2;i<=n-k+1;i++){
            x=((m-1)*dp[i-1])%mod;
            x=(x*bigmod(m,n-i-k+1))%mod;
            //x=(x*m)%mod;
            ans=(ans+x)%mod;
        }
        ans=(ans+mod)%mod;
        cout<<ans<<endl;
    }
}

