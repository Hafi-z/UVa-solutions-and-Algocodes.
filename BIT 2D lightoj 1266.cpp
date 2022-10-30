#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define n 1003
ll tree[n][n];
//ll a[n][n];
bool b[n][n];
void update(ll x,ll y,ll val)
{
    while(x<=n){
        int y1=y;
        while(y1<=n){
            tree[x][y1]+=val;
            y1+=(y1 & -y1);
        }
        x+=(x & -x);
    }
}

int read(ll x, ll y)
{
    ll sum=0;
    while(x>0){
        int y1=y;
        while(y1>0){
            sum+=tree[x][y1];
            y1-=(y1 & -y1);
        }
        x-=(x & -x);
    }
    return sum;
}

ll query(ll x1,ll y1,ll x2,ll y2)
{
    return read(x2,y2)-read(x2,y1-1)-read(x1-1,y2)+read(x1-1,y1-1);
}

int main()
{
    ll t,q,ans,d,x1,y1,x2,y2;
    cin>>t;
    for(int i=1;i<=t;i++){
        scanf("%lld",&q);
        printf("Case %d:\n",i);
        memset(b,0,sizeof b);
        memset(tree,0,sizeof tree);
        while(q--){
           scanf("%lld",&d);
        switch(d){
        case 0:
            scanf("%lld %lld",&x1,&y1);x1+=1;y1+=1;
            if(!b[x1][y1]){
                b[x1][y1]=true;
                update(x1,y1,1);
            }
            break;
        case 1:
            scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
            x1+=1;y1+=1;x2+=1;y2+=1;
            printf("%lld\n",query(x1,y1,x2,y2));
            break;
          }
        }
    }

    return 0;
}
