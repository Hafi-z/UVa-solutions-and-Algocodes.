#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll>p;p.push_back(2);
    for(int i=3;i<=100;i+=2){ll x=0;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){x=2;break;}
        }
        if(x!=2)p.push_back(i);
    }
    //for(int i=0;i<p.size();i++)cout<<p[i]<<endl;
    ll t,c=0;
    cin>>t;
    while(t--){
        ll n,y;
        cin>>n;y=n;
        printf("Case %lld: %lld = ",++c,n);
        for(int i=0;i<1ll;i++){
            if(n/p[i]==0)break;
            ll cnt=0;
            y=n;
            while(y){
                cnt+=(y/p[i]);
                y/=p[i];
            }
            printf("%lld (%lld)",p[i],cnt);
        }
        for(int i=1;i<p.size();i++){
            if(n/p[i]==0)break;
            ll cnt=0;
            y=n;
            while(y){
                cnt+=(y/p[i]);
                y/=p[i];
            }
            printf(" * %lld (%lld)",p[i],cnt);
        }
        printf("\n");
    }
}

