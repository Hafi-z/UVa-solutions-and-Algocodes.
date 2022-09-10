#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007



int main()
{_
//    freopen("snakes.in", "r", stdin);
//    freopen("snakes.out", "w", stdout);
    ll t=1,ca=1;
    //cin>>t;
    while(t--){///problem: https://dmoj.ca/problem/ioi04p4
        ll w,h,n;
        cin>>w>>h>>n;
        ll a[n+1];
        ll a2[n+1];
        ll dp[h+1][w+1];
        for(int i=1;i<=n;i++){
            cin>>a[i]>>a2[i];
        }

        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++)dp[i][j]=360001;
        }

        for(int i=0;i<=w;i++)dp[0][i]=0;
        for(int i=0;i<=h;i++)dp[i][0]=0;

//        for(int i=1;i<=n;i++){
//            for(int j=a2[i];j<=h;j+=a2[i]){
//                for(int k=a[i];k<=w;k+=a[i]){
//                    dp[j][k]=0;
//                }
//            }
//        }

        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                dp[i][j]=min({dp[i][j],dp[i][j-1]+i,dp[i-1][j]+j});
                for(int k=1;k<=n;k++){
                    if(i>=a2[k]&&j>=a[k]){
                        dp[i][j]=min({dp[i][j],dp[i-a2[k]][j]+dp[a2[k]][j-a[k]],dp[i][j-a[k]]+dp[i-a2[k]][a[k]]});
                        ///We are placing each required plate at i,j and
                        ///calculating ans as it will be min of [dp(i-h,j), dp(i-(i-h),j-k)=>because
                        ///calculating ans for it will be same from (0,0) to (i-(i-h),j-k)] and
                        ///dp(i,j-k), dp(i-h,j-(j-k)).
                    }
                }
            }
        }

//        for(int i=1;i<=h;i++){
//            for(int j=1;j<=w;j++){
//                cout<<dp[i][j]<<" ";
//            }cout<<endl;
//        }
        cout<<dp[h][w];
    }
}

