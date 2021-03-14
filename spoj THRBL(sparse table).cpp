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
            ST[k][i]=max(x,y);
        }
    }
}

int RMQ(int i,int j)
{
    int k=log2(j-i+1);
    int x=ST[k][i];
    int y=ST[k][j-(1<<k)+1];
    return max(x,y);
}
///problem:https://www.spoj.com/problems/THRBL/
int main()
{_
    ll t=1;
    //cin>>t;
    while(t--){
        ll n,m,cnt=0;
        cin>>n>>m;
        ll l1[n+1];
        for(int i=1;i<=n;i++){
            cin>>l1[i];
            a[i-1]=l1[i];
        }
        Compute_ST(n);
        for(int i=1;i<=m;i++){
            ll l,r,rp;
            cin>>l>>r;rp=l;
            if(abs(l-r)<=1){cnt++;continue;}
            if(l>r)swap(l,r);
            ll x=RMQ(l,r-2);
            if(x>l1[rp]);
            else cnt++;
            //debug(x)
        }
        cout<<cnt<<endl;
    }
}

