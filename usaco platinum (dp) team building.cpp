#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000009
#define mod2 998244353
#define inf LLONG_MAX

ll n,m,k;
ll a[1005];
ll a2[1005];
ll dp[1005][1005][15];

ll sol(ll i,ll j,ll cnt)
{
    if(i>n&&j>m)return cnt==k;
    if(cnt>k||i>n+1||j>m+1)return 0;
    if(dp[i][j][cnt]!=-1)return dp[i][j][cnt];

    ll z=0;
    if(i<=n&&j<=m&&a[i]>a2[j])z+=sol(i+1,j+1,cnt+1);
    z+=sol(i+1,j,cnt);
    z+=sol(i,j+1,cnt);
    if(i<=n&&j<=m)z-=sol(i+1,j+1,cnt);///over count reducing
    ///because this state is counted twice
    ///draw states to find that
    z%=mod;
    z=(z+mod)%mod;
    return dp[i][j][cnt]=z;
}

int main()
{_
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);
    ll t=1,ca=1;
    //cin>>t;
    while(t--){///problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=673
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>a2[i];
        }
        sort(a+1,a+n+1,greater<int>());
        sort(a2+1,a2+m+1,greater<int>());
        memset(dp,-1,sizeof dp);
        cout<<sol(1,1,0);
    }
}

