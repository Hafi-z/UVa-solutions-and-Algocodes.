#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007
#define mod2 998244353
#define inf LLONG_MAX

ll arr[500005];
ll lst[500005];
ll tree[500005],n,q;
vector<ll>v[500005];

void update(ll idx,ll val,ll n)
{
    while(idx<=n){
        tree[idx]+=val;
        idx+=(idx & -idx);
    }
}

int read(ll idx)
{
    ll sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx & -idx);
    }
    return sum;
}

int main()
{_
//    freopen("spainting.in", "r", stdin);
//    freopen("spainting.out", "w", stdout);
    ll t=1,ca=1;
    //cin>>t;
    while(t--){///problem: https://atcoder.jp/contests/abc174/tasks/abc174_f
        ///offline technique with BIT.
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        vector<pair<ll,ll>>v2;

        map<pair<ll,ll>,ll>mp;
        for(int i=1;i<=q;i++){
            ll l,r;
            cin>>l>>r;
            v2.push_back({l,r});
            v[r].push_back(l);
        }
        for(int i=1;i<=n;i++){
            if(lst[arr[i]]!=0)update(lst[arr[i]],-1,n);
            update(i,1,n);
            lst[arr[i]]=i;
            for(auto j:v[i]){
                ll l,r;
                l=j,r=i;
                mp[{l,r}]=read(r)-read(l-1);
            }
        }
        for(auto i:v2){
            cout<<mp[{i.first,i.second}]<<endl;
        }
    }
}

