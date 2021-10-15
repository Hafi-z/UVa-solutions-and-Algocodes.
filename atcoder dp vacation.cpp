#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007

ll n,hp[100005][4],dp[100005][4];

ll solve(ll i,ll j)
{
    if(i==1)return hp[i][j];

    if(dp[i][j]!=-1)return dp[i][j];

    ll ans=0;
    for(int k=1;k<=3;k++){
        if(k!=j)ans=max(ans,solve(i-1,k)+hp[i][j]);
    }
    return dp[i][j]=ans;
}

int main()
{_
    ll t=1,ca=1;
    //cin>>t;
    while(t--){///https://atcoder.jp/contests/dp/tasks/dp_c
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>hp[i][j];
                dp[i][j]=-1;
            }
        }
        cout<<max({solve(n,1),solve(n,2),solve(n,3)})<<endl;
    }
}

