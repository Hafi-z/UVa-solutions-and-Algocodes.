#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;

ll l1[17+1][4],dp[1<<17][18],n;

ll func(ll mask,ll pos)
{
    if(mask==(1<<n)-1)return abs(l1[0][0]-l1[pos][0])+abs(l1[0][1]-l1[pos][1])+max(0ll,l1[0][2]-l1[pos][2]);
    if(dp[mask][pos]!=-1)return dp[mask][pos];
    ll ans=INT_MAX;
    for(int city=0;city<n;city++){
        if(!(mask&(1<<city))){
            ans=min(ans,func(mask|(1<<city),city)+abs(l1[city][0]-l1[pos][0])+abs(l1[city][1]-l1[pos][1])+max(0ll,l1[city][2]-l1[pos][2]));
        }
    }
    return dp[mask][pos]=ans;
}

int main()
{
    ///Travelling salesman classical dp problem
    ///Problem: https://atcoder.jp/contests/abc180/tasks/abc180_e
    ///Tutorial with cpp code: https://www.youtube.com/watch?v=JE0JE8ce1V0
    ///Tutorial: Mahbubul Hasan's book.
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>l1[i][0]>>l1[i][1]>>l1[i][2];
    }
    memset(dp,-1,sizeof dp);
    cout<<func(1,0);
}

