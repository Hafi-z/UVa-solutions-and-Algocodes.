#include<iostream>
using namespace std;
#define ll long long
#define max 100005

int sum[max];
int tree[max*4];
void STB(int at,int L,int R)
{
    //int sum[at]=0;
    if(L==R){
        tree[at]=sum[L];
        return;
    }
    int mid=(L+R)/2;
    STB((at<<1)+1,L,mid);
    STB((at<<1)+2,mid+1,R);
    tree[at]=tree[(at<<1)+1]+tree[(at<<1)+2];
    //return sum[at];
}

void update(int at,int L,int R,int pos,int u)
{
    if(L==R){
        tree[at]=u;///u poriman barate hobe tai +u.
        return;
    }
    int mid=(L+R)>>1;
    if(pos<=mid)update((at<<1)+1,L,mid,pos,u);
    else update((at<<1)+2,mid+1,R,pos,u);

    tree[at]=tree[(at<<1)+1]+tree[(at<<1)+2];
}

int query(int at,int L,int R,int l,int r)
{
    if(L>r || R<l)return 0;
    else if(L>=l && R<=r)return tree[at];

    int mid=(L+R)>>1;
    int x=query((at<<1)+1,L,mid,l,r);
    int y=query((at<<1)+2,mid+1,R,l,r);

    return x+y;
}

int main()
{
    ll n,t,a,b,c,q,x12,cases=0;
    scanf("%lld",&t);
    while(t--){printf("Case %lld:\n",++cases);
        //cin>>n>>q;
        scanf("%lld %lld",&n,&q);
        for(int i=0;i<n;i++){scanf("%d",&sum[i]);}
        STB(0,0,n-1);
        while(q--){
            scanf("%lld",&x12);
        switch(x12){
        case 1:
            scanf("%lld",&a);//c=query(0,0,n-1,a,a);
            //cout<<sum[a]<<endl;
            printf("%d\n",sum[a]);
            update(0,0,n-1,a,0);sum[a]=0;
            break;
        case 2:
            scanf("%lld %lld",&a,&b);sum[a]+=b;
            update(0,0,n-1,a,sum[a]);
            break;
        case 3:
            scanf("%lld %lld",&a,&b);
            //cout<<query(0,0,n-1,a,b)<<endl;
            printf("%d\n",query(0,0,n-1,a,b));
            break;
        }
        }
    }

    return 0;
}
