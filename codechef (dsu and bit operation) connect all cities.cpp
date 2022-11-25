#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007
#define mod2 998244353
#define inf LLONG_MAX

ll n,a[1000005],a2[1000005],sz[1000005];

void initialize()
{
    for(int i=1;i<=n;i++)a[i]=i,sz[i]=1;
}

ll root(ll i)
{
    while(a[i]!=i)i=a[i];
    return i;
}

void unionn(ll aa,ll b)
{
    ll root_a=root(aa);
    ll root_b=root(b);
    if(sz[root_a]>sz[root_b]){
        a[root_b]=a[root_a];
        sz[root_a]+=sz[root_b];
    }
    else{
        a[root_a]=a[root_b];
        sz[root_b]+=sz[root_a];
    }
}

bool findd(ll a,ll b)
{
    if(root(a)==root(b))return true;
    return false;
}

int main()
{_
//    freopen("feast.in", "r", stdin);
//    freopen("feast.out", "w", stdout);
    ll t=1,ca=1;
    cin>>t;
    ///CHECK FROM HERE***
    while(t--){///https://www.codechef.com/problems/CNCTCT
        ll ans=0,ok=0,edgecnt=0;
        cin>>n;
        ll hoise[35],cnt[35];
        vector<ll>v[35+1];
        unordered_map<ll,ll,custom_hash>mp;
        for(int i=0;i<=30;i++){
            hoise[i]=0;
            cnt[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>a2[i];
            if(a2[i]==0)ok=100;
            ll x=0,y=a2[i];
            while(y>0){
                if(y%2==1){
                    v[x].push_back(i);
                    cnt[x]++;
                }
                y/=2;
                x++;
            }
        }//debug(55)
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        initialize();
        for(int i=0;i<=29;i++){
            ll x=1ll<<i,y=v[i].size();
            for(int j=1;j<y;j++){
                if(!findd(v[i][j-1],v[i][j])){
                    ans+=x;
                    unionn(v[i][j-1],v[i][j]);
                    edgecnt++;
                }
            }
        }
        if(edgecnt==n-1)cout<<ans<<endl;
        else cout<<-1<<endl;
    }
}

