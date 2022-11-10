#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007
#define mod2 998244353
#define inf LLONG_MAX



int main()
{_
//    freopen("spainting.in", "r", stdin);
//    freopen("spainting.out", "w", stdout);
    ll t=1,ca=1;
    //cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        ll a[n+5];
        ll pre[n+5];
        ll sum[n+5];
        map<ll,ll>lst,lst2;
        pre[0]=0;
        sum[0]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pre[i]=pre[i-1]^a[i];
            sum[i]=sum[i-1]+a[i];
        }
        vector<ll>v[n+1];
        vector<pair<ll,ll>>v2;
        map<pair<ll,ll>,ll>mp;
        for(int i=1;i<=q;i++){
            ll b,c;
            cin>>b>>c;
            v[c].push_back(b);
            v2.push_back({b,c});
        }///OFLINE QUERY TECHNIQUE
        for(int i=1;i<=n;i++){
            ll l,r;
            for(auto j:v[i]){
                l=j,r=i;
                if(sum[r]-sum[l-1]==0)mp[{l,r}]=0;
                else if((r-l+1)%2!=0){
                    if(pre[l-1]==pre[r])mp[{l,r}]=1;
                    else mp[{l,r}]=-1;
                }
                else{
                    if((pre[l-1]==pre[r])&&(pre[l]==pre[r]||pre[r]==pre[r-1]))mp[{l,r}]=1;
                    else if((pre[l-1]==pre[r])&&((l%2!=0&&lst[pre[r]]>=l)||(l%2==0&&lst2[pre[r]]>=l)))mp[{l,r}]=2;
                    else mp[{l,r}]=-1;
                }
            }
            if(i%2!=0)lst[pre[i]]=i;
            else lst2[pre[i]]=i;
        }
        for(auto i:v2){
            cout<<mp[{i.first,i.second}]<<endl;
        }
    }
}

