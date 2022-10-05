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
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    ll t=1,ca=1;
    //cin>>t;
    while(t--){
        ///problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=622
        ///tutorial: https://www.youtube.com/watch?v=6PbyEBH09u8
        ll n,k,ans=inf;
        cin>>n>>k;
        ll a[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int rot=1;rot<=n;rot++){
            rotate(a+1,a+1+1,a+n+1);///linear barn by making each room as position 1 by rotating 1 left shift the whole array
            vector<vector<ll>>dp(k+1,vector<ll>(n+1,inf));
            for(int i=1;i<=k;i++)dp[i][0]=0;///opening any number of external door value is 0 without using any room
            dp[1][1]=0;///fixing 1st external door at position 1 always
            for(int i=2;i<=n;i++){
                dp[1][i]=dp[1][i-1]+(i-1)*a[i];
            }
            for(int i=2;i<=k;i++){
                for(int j=1;j<=n;j++){
                    ll s=0,s2=0;
                    for(int l=j;l>=1;l--){///considering a new door at l
                        s+=s2;///calculating sum from l+1 to current pos j
                        dp[i][j]=min(dp[i][j],dp[i-1][l-1]+s);///dp[i-1][l-1]=>without taking new door, the min sum till l-1
                        s2+=a[l];
                    }
                }
            }
//            for(int i=1;i<=k;i++){///for checking values are correct or not
//                for(int j=1;j<=n;j++){
//                    cout<<dp[i][j]<<" ";
//                }cout<<endl;
//            }
//            debug(dp[k][n])
            ans=min(ans,dp[k][n]);
        }
        cout<<ans<<endl;
    }
}

