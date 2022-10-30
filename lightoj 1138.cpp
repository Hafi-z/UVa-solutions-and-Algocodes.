#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,c=0;
    cin>>t;

    while(t--){
        ll n,y=1e18+1;ll lo=1,hi=400000015;
        cin>>n;ll mid=(lo+hi)/2;
        while(lo<=hi){
            ll cnt=0,x;x=mid;
            while(x){
                cnt+=(x/5);
                x/=5;
            }
            if(n==cnt){y=min(y,mid);hi=mid-1;}
            else if(cnt<n)lo=mid+1;
            else hi=mid-1;
            mid=(lo+hi)/2;
        }
        if(y==1e18+1)printf("Case %lld: impossible\n",++c);
        else printf("Case %lld: %lld\n",++c,y);
    }
}

