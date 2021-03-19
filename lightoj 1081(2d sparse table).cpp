#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<x<<"DE\n";
#define debug2(x,y) cout<<x<<" "<<y<<"DE\n";
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007

ll ST[10+5][505][505],s;
ll a[505][505];

void Compute_ST(ll n)
{
    for(int k=1;(1<<k)<=n;k++){
        for(int i=0;i+(1<<k)<=n;i++){
            for(int j=0;j+(1<<k)<=n;j++){
                ST[k][i][j]=max({ST[k-1][i][j],ST[k-1][i][j+(1<<k-1)],ST[k-1][i+(1<<k-1)][j],ST[k-1][i+(1<<k-1)][j+(1<<k-1)]});
            }
        }
    }
}

int RMQ(ll i,ll j)
{
    ll k=log2(s-1+(i-1)-(i-1)+1);
    ll x=max(ST[k][i-1][j-1],ST[k][i-1][s-1+j-1-(1<<k)+1]);
    ll y=max(ST[k][i-1+s-1-(1<<k)+1][j-1],ST[k][i-1+s-1-(1<<k)+1][s-1+j-1-(1<<k)+1]);
    return max(x,y);
}

int main()
{_
    ll t=1,ca=1;
    cin>>t;
    while(t--){
        ll n,m,ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ll aa;
                cin>>aa;
                ST[0][i-1][j-1]=aa;
            }
        }

        Compute_ST(n);

        cout<<"Case "<<ca++<<":\n";
        while(m--){
            ll b,c;
            cin>>b>>c>>s;
            //b--,c--;
            ll ans=0;

            ans=RMQ(b,c);
            cout<<ans<<endl;
        }
    }
}

