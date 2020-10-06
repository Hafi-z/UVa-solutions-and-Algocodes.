
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 2000000011
#define debug(x) cout<<x<<"DE\n";
#define debug2(x,y) cout<<x<<" "<<y<<"DE\n";

ll bigmod(ll b,ll p)
{
    ll an=1;b%=MOD;
    while(p>0){
        if(p&1)an=an*b%MOD;
        b=b*b%MOD;
        p>>=1;
    }
    return an;
    ///BINARY EXPONENTATION///
    ///TAKEN FROM "e-maxx"///
}

int main()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){
        ll N;
        cin>>N;
        printf("Case #%d: %lld\n",i,bigmod(N,N-2));
    }
}
