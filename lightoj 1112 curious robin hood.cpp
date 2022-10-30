#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define ll long long int
ll a[100001],tree[100001];
///BINARY INDEXED TREE///

void update(ll idx,ll val,ll n)
{
    while(idx<=n){
        tree[idx]+=val;
        idx+=(idx & -idx);
    }
}

int read(ll idx)
{
    int sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx & -idx);
    }
    return sum;
}

int main()
{
    ll t,n,q,b,c,d;
    //cin>>t>>n>>q;
    scanf("%lld",&t);
    for(int j=1;j<=t;j++){
           scanf("%lld %lld",&n,&q);
    for(int i=1;i<=n;i++){
        //cin>>a[i];
        scanf("%lld",&a[i]);
        update(i,a[i],n);
    }
    printf("Case %d:\n",j);
    for(int i=1;i<=q;i++){
        //cin>>b;
        scanf("%lld",&b);
        if(b==1){
            //cin>>c;
            scanf("%lld",&c);
            ll ans=read(c+1)-read(c);
            update(c+1,-ans,n);
            //cout<<a[c+1]<<endl;
            printf("%lld\n",ans);
            //a[c+1]=0;
        }
        else if(b==2){
            //cin>>c>>d;
            scanf("%lld %lld",&c,&d);
            update(c+1,d,n);
            a[c+1]+=d;
        }
        else{
            //cin>>c>>d;
            scanf("%lld %lld",&c,&d);
            //cout<<read(d+1)-read(c)<<endl;
            ll ans=read(d+1)-read(c);
            printf("%lld\n",ans);
        }
    }
    for(int i=1;i<=n;i++)tree[i]=0;
    }
    return 0;
}
