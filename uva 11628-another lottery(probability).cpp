#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<x<<"DE\n";
#define debug2(x,y) cout<<x<<" "<<y<<"DE\n";

int main()
{
    while(1){
        ll n,m,a,tot=0;
        cin>>n>>m;
        if(!n&&!m)break;
        ll l1[n+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<m;j++)cin>>a;
            cin>>l1[i];
            tot+=l1[i];
        }
        for(int i=1;i<=n;i++){
            ll x=l1[i],y=tot;
            ll z=__gcd(x,y);
            printf("%lld / %lld\n",x/z,y/z);
        }
    }
}

