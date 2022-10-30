#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007
#define mod2 998244353
#define inf LLONG_MAX

string s;
ll dp[65][65];
ll sol(ll i,ll j)
{
    if(i==j)return 1;
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll x=0,y=0,z=0;
    x=sol(i+1,j);
    x+=sol(i,j-1);
    x-=sol(i+1,j-1);
    if(s[i-1]==s[j-1])x+=sol(i+1,j-1)+1;

    return dp[i][j]=x;
}

int main()
{//_
//    freopen("team.in", "r", stdin);
//    freopen("team.out", "w", stdout);
    ll t=1,ca=1;
    cin>>t;
    while(t--){///https://lightoj.com/problem/the-specials-menu
        cin>>s;
        memset(dp,-1,sizeof dp);
        printf("Case %lld: ",ca++);
        cout<<sol(1,s.size())<<endl;
    }
}

