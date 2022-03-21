#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007
#define mod2 998244353

ll n,m,k,a[20],dp[20][1<<19],mp[20][20];
//map<pair<ll,ll>,ll>mp;

ll sol(ll prev,ll mask)
{//debug2(prev,mask)
    if(__builtin_popcountll(mask)==m)return 0;

    if(dp[prev][mask]!=-1)return dp[prev][mask];

    ll ans=0;
    for(int j=0;j<n;j++){
        if(!(mask&(1<<j))){
            ans=max(ans,mp[prev][j]+a[j]+sol(j,(mask|(1<<j))));
        }
    }
    return dp[prev][mask]=ans;
}

int main()
{_
    ll t=1,ca=1;
    //cin>>t;
    while(t--){///https://codeforces.com/problemset/problem/580/D
        cin>>n>>m>>k;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=1;i<=k;i++){
            ll b,c,d;
            cin>>b>>c>>d;
            mp[b-1][c-1]=d;
        }
        memset(dp,-1,sizeof dp);
        ll ans2=0;
        for(int i=0;i<n;i++){//memset(dp,-1,sizeof dp);
            ans2=max(ans2,sol(i,(1<<i))+a[i]);
        }
        cout<<ans2;
    }
}
