#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007

ll dp[10005][105],n,m,a[105];

ll solve(ll sum,ll idx)
{
    if(sum==0)return 1;
    if(idx<1)return 0;

    if(dp[sum][idx]!=-1)return dp[sum][idx];

    ll ans=0;
    ans|=solve(sum,idx-1);
    if(sum-a[idx]>=0)ans|=solve(sum-a[idx],idx-1);

    return dp[sum][idx]=ans;
}

int main()
{_
    ll t=1,ca=1;
    cin>>t;
    while(t--){///problem: https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/exponential-subset-f78d066f/
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        //memset(dp,-1,sizeof dp);

        for(int j=0;j<=n;j++)dp[0][j]=1;
        for(int i=1;i<=10000;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i][j-1];
                if(i-a[j]>=0)dp[i][j]|=dp[i-a[j]][j-1];
            }
        }

        for(int i=1;i<=n;i++){
            ll x=a[i]*a[i],ok=0;
            while(x<=10000){
                ///for recursive-> if(solve(x,n)){ok=1;break;}
                if(dp[x][n]){ok=1;break;}
                x*=a[i];
                //debug(x)
            }
            cout<<ok<<" ";
        }cout<<endl;
    }
}

