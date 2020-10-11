#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<x<<"DE\n";
#define debug2(x,y) cout<<x<<" "<<y<<"DE\n";

ll n,k,l1[10005],ok;
ll positive_dp[10005][105];
ll negative_dp[10005][105];

ll subset(ll i,ll sum)
{
    if(i>n){
        if(sum%k==0)return 1;
        else return 0;
    }
    if(sum>=0&&positive_dp[i][sum]!=-1)return positive_dp[i][sum];
    if(sum<0&&negative_dp[i][-sum]!=-1)return positive_dp[i][-sum];

    ll c1=subset(i+1,(sum+l1[i])%k);
    ll c2=subset(i+1,(sum-l1[i])%k);
    if(sum>=0)positive_dp[i][sum]=max(c1,c2);
    else negative_dp[i][-sum]=max(c1,c2);
    return max(c1,c2);
}

int main()
{
    ll t;
    cin>>t;
    while(t--){
        cin>>n>>k;ok=0;
        memset(positive_dp, -1, sizeof positive_dp);
        memset(negative_dp, -1, sizeof negative_dp);
        for(int i=1;i<=n;i++)cin>>l1[i];

        if(subset(2,l1[1]%k))cout<<"Divisible\n";
        else cout<<"Not divisible\n";
    }
}

