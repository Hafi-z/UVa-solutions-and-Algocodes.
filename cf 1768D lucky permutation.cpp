#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007
#define mod2 998244353
#define inf LLONG_MAX
#define yes cout << "YES\n"
#define yes2 cout << "Yes\n"
#define no cout << "NO\n"
#define no2 cout << "No\n"
#define forn(a,n) for(int i=1;i<=n;i++)cin>>a[i];



int main()
{_
//    freopen("feast.in", "r", stdin);
//    freopen("feast.out", "w", stdout);
    ll t=1,ca=1;
    cin>>t;
    ///CHECK FROM HERE***
    while(t--){///https://codeforces.com/contest/1768/problem/D
        ll n;
        cin>>n;
        ll a[n+1],x=0;
        ll a2[n+1];
        vector<ll>v(n+1);
        vector<ll>v2(n+1);
        vector<ll>c(n+1,-1);
        forn(a,n)
        for(int i=1;i<=n;i++){
            //cin>>a[i];
            a2[i]=a[i];
            v[a[i]]=i;
            if(a[i]==i)x++;
        }v2=v;
        ll ans=0;
        ll ok=1;
        for(int i=1;i<=n;i++){
            ll b=i;
            if(c[b]==-1){
                while(c[b]==-1){
                c[b]=ok;
                b=a[b];
            }
            ok+=1;
            }

        }
        //debug(ok)
        ans=n-(ok-1);
        ///min swaps req to sort array is n-number of cycles;
        ///n-number of cycles is same as sum of each cycle size-1;
        ///for the above line=> https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
        for(int i=1;i<n;i++){//debug(c[i])
            if(c[i]==c[i+1]){
                ans-=1;
                ok=0;break;
            }
        }
        if(ok==0)cout<<ans<<endl;
        else cout<<ans+1<<endl;
    }
}

