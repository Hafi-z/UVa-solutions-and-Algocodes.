#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<x<<"DE\n";
#define debug2(x,y) cout<<x<<" "<<y<<"DE\n";
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007

ll ST[(ll)log2(100005)+5][100005];
ll a[100005];

void Compute_ST(ll n)
{
    for (int i=0;i<n;i++)ST[0][i]=a[i];
    for (int k=1;(1<<k)<n;k++){
        for (int i=0;i+(1<<k)<=n;i++){
            ll x=ST[k-1][i];
            ll y=ST[k-1][i+(1<<k-1)];
            ST[k][i]=__gcd(x,y);
        }
    }
}

int RMQ(ll i,ll j)
{
    ll k=log2(j-i+1);
    ll x=ST[k][i];
    ll y=ST[k][j-(1<<k)+1];
    return __gcd(x,y);
}

int main()
{_
    ll t=1;
    //cin>>t;
    while(t--){
        ll n,m;
        cin>>n;
        ll l1[n+1];
        for(int i=1;i<=n;i++){
            cin>>l1[i];
            a[i-1]=l1[i];
        }
        cin>>m;//debug(5)
        Compute_ST(n);
        //debug(5)
        map<ll,ll>ans;
        //debug(5)
        for(ll i=1;i<=n;i++){
            ll cur=i;
            //debug(5)
            while(cur<=n){
                ll lo=cur+1,hi=n,target=RMQ(i-1,cur-1);
                while(lo<=hi){
                    ll mid=(lo+hi)/2;
                    if(RMQ(i-1,mid-1)==target)lo=mid+1;
                    else hi=mid-1;
                }
                ans[target]+=lo-cur;
                cur=lo;
            }
        }
        //debug(5)
        while(m--){
            ll b;
            cin>>b;
            cout<<ans[b]<<endl;
        }
    }
}

