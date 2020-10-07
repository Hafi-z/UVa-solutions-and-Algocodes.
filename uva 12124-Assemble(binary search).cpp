#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<x<<"DE\n";
#define debug2(x,y) cout<<x<<" "<<y<<"DE\n";

int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n,b;
        cin>>n>>b;
        string type,name;
        map<string,vector<pair<ll,ll>>>mp;
        for(int i=1;i<=n;i++){
            ll a,c;
            cin>>type>>name>>a>>c;
            mp[type].push_back({a,c});
        }
        ll l=0,r=1e9,mid,cost=0,opt=0;
        while(l<=r){
            mid=(l+r)/2;
            cost=0;
            for(auto it=mp.begin();it!=mp.end();it++){ll lagtase=1e9;
                for(auto it2=(it->second).begin();it2!=(it->second).end();it2++){
                    if(it2->second>=mid)lagtase=min(lagtase,it2->first);
                }
                cost+=lagtase;
                if(cost>b)break;
            }
            if(cost<=b)l=mid+1,opt=max(opt,mid);
            else r=mid-1;
        }
        cout<<opt<<endl;
    }
}

