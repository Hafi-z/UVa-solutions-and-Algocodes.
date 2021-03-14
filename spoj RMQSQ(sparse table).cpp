#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<x<<"DE\n";
#define debug2(x,y) cout<<x<<" "<<y<<"DE\n";
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007

ll ST[(ll)log2(100005)+5][100005];
ll a[100005];

void Compute_ST(int n)
{
    for (int i=0;i<n;i++)ST[0][i]=a[i];
    for (int k=1;(1<<k)<n;k++){
        for (int i=0;i+(1<<k)<=n;i++){
            ll x=ST[k-1][i];
            ll y=ST[k-1][i+(1<<k-1)];
            ST[k][i]=min(x,y);
        }
    }
}

int RMQ(int i,int j)
{
    int k=log2(j-i+1);
    int x=ST[k][i];
    int y=ST[k][j-(1<<k)+1];
    return min(x,y);
}
///https://www.spoj.com/problems/RMQSQ/
int main()
{_
    ll t=1;
    //cin>>t;
    while(t--){
        ll n,q;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        Compute_ST(n);
        cin>>q;
        while(q--){
            ll l,r;
            cin>>l>>r;
            cout<<RMQ(l,r)<<endl;
        }
    }
}
