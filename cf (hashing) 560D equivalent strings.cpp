#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007
#define mod2 998244353
#define inf LLONG_MAX
#define yes cout << "YES\n"
#define yes2 cout << "Yes\n"
#define no cout << "NO\n"
#define no2 cout << "No\n"
#define forn2(a,n) for(int i=1;i<=n;i++)cin>>a[i];
#define forn(x,n) for(ll i=x;i<=n;i++)

string s,s2;

ll p[200005];
ll ans=0,n;
ll ha[200005];///1 indexing
ll hb[200005];///1 indexing
ll m=1e9+9;///mod=m, p=prime=31;

///substrhash(a,b)=> mod+h[b]-h[a-1]*p[n-a])%mod
///cp algo theke=> mod inv korar theke ekta power mult kore both hash ke equal kora jay

ll sol(ll la,ll ra,ll lb,ll rb)
{
    ll x=(((ha[ra]-ha[la-1])%m)*p[n-la])%m;///substr of a
    ll y=(((hb[rb]-hb[lb-1])%m)*p[n-lb])%m;///substr of b
    if(x<0)x+=m;
    if(y<0)y+=m;
//    debug2(la,ra)
//    debug2(lb,rb)
//    debug2(x,y)
    if(x==y)return 1;
    if((ra-la+1)%2!=0)return 0;

    ll mida=(ra+la)/2;
    ll midb=(rb+lb)/2;
//    debug(mida)
//    debug(midb)
    ll z=(sol(la,mida,midb+1,rb)&&sol(mida+1,ra,lb,midb))||(sol(la,mida,lb,midb)&&sol(mida+1,ra,midb+1,rb));
//    ll z=(sol(la,mida,lb,midb));
//    ll z2=(sol(mida+1,ra,midb+1,rb));
//    ll z3=(sol(mida+1,ra,lb,midb));
//    ll z4=(sol(la,mida,midb+1,rb));
//    return ((z&&z2)||(z3&&z4));
    return z;
}

int main()
{_
//    freopen("feast.in", "r", stdin);
//    freopen("feast.out", "w", stdout);
    ll t=1,ca=1;
    //cin>>t;
    ///CHECK FROM HERE***
    for(int i=1;i<=200000;i++){p[0]=1;p[i]=(p[i-1]*31ll)%m;}
    while(t--){///https://codeforces.com/contest/560/problem/D
        ///helped a lot=> https://codeforces.com/contest/560/submission/12179731
        ///https://cp-algorithms.com/string/string-hashing.html#fast-hash-calculation-of-substrings-of-given-string
        cin>>s>>s2;

        ll nn=s.size();n=nn;
        for(int i=1;i<=nn;i++)ha[i]=(ha[i-1]+(p[i-1]*(s[i-1]-'a'+1))%m)%m;
        ll nn2=s2.size();
        for(int i=1;i<=nn2;i++)hb[i]=(hb[i-1]+(p[i-1]*(s2[i-1]-'a'+1))%m)%m;
        //debug2(ha[nn],hb[nn])
        if(sol(1,nn,1,nn))yes;
        else no;
    }
}

