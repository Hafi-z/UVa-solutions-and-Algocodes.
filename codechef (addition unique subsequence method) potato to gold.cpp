#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007
#define mod2 998244353
#define inf LLONG_MAX

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
//    freopen("spainting.in", "r", stdin);
//    freopen("spainting.out", "w", stdout);
    ll t=1,ca=1;
    cin>>t;
    while(t--){///https://www.codechef.com/problems/SIMPLEARRAY
        ll n,k,ans=1;
        cin>>n>>k;
        ll a[n+1];
        map<ll,ll>mp;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]=a[i]%k;
            mp[a[i]]++;
        }
        for(int i=1;i<(k+1)/2;i++){
            ll x=mp[i],y=mp[k-i];
            ans=(ans*(bigmod(2ll,x)+bigmod(2ll,y)-1)%mod)%mod;
        }
        ll x=(mp[0]+1);
        if(k%2==0)x=(x*(mp[k/2]+1))%mod;
        ans=(ans*x)%mod;
        ans=(ans+mod)%mod;
        cout<<ans<<endl;
    }
}

