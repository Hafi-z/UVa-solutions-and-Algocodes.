#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll tree[100001];
ll a[100001];

void update(ll idx,ll val,ll n)
{
    while(idx<=n){
        tree[idx]+=val;
        idx+=(idx & -idx);
    }
}

int read(ll idx)
{
    ll sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx & -idx);
    }
    return sum;
}

int main()
{
    ll t,n,q,ans,c,d;
    char b;
    string s;
    //cout<<~0<<" "<<~1<<endl;
    scanf("%lld",&t);
    for(int i=1;i<=t;i++){
        cin>>s;
        n=s.size();
        for(int j=1;j<=n;j++){
            a[j]=s[j-1]-'0';
            //update(j,a[j],n);
        }
        for(int k=0;k<=n;k++)tree[k]=0;
        scanf("%lld",&q);
        printf("Case %d:\n",i);
        for(int j=1;j<=q;j++){
            getchar();
            scanf("%c",&b);
            switch(b)
            {
            case 'I':
                scanf("%lld %lld",&c,&d);
                //read(d)-read(c-1);
                update(c,1,n);///???
                update(d+1,-1,n);///???
                break;
            case 'Q':
                scanf("%lld",&c);
                ans=read(c)%2;
                if(ans==0)printf("%lld\n",0^a[c]);///never flipped.
                else printf("%lld\n",1^a[c]);///naughty flipping :).
                break;
            }
        }
    }

    return 0;
}
