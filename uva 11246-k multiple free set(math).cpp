#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<x<<"DE\n";
#define debug2(x,y) cout<<x<<" "<<y<<"DE\n";

int main()
{
    ll t;
    cin>>t;
///EDITORIAL: https://www.quora.com/UVA-11246-Multiple-free-set-How-to-solve-it-without-lists
    while(t--){
        ll n,k;
        cin>>n>>k;
        map<ll,ll>vis;
        ll cnt=0;
        ll sign=-1,l=k;
        while(n/l>0){
            cnt+=sign*(n/l);
            l*=k;
            sign*=-1;
        }
        cout<<n+cnt<<endl;
    }
}

