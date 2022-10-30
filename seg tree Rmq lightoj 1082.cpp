#include<iostream>
using namespace std;
#define ll long long
#define max 100005
#define MAX 1000000000

int ar[max];
int tree[max*4];
void STB(int at,int L,int R)
{
    //int sum[at]=0;
    if(L==R){
        tree[at]=ar[L];
        return;
    }
    int mid=(L+R)/2;
    STB(2*at,L,mid);
    STB(2*at+1,mid+1,R);
    tree[at]=min(tree[2*at],tree[2*at+1]);
    //return sum[at];
}

void update(int at,int L,int R,int pos,int u)
{
    if(L==R){
        tree[at]+=u;///u poriman barate hobe tai +u.
    }
    int mid=(L+R)/2;
    if(pos<=mid)update(at*2,L,mid,pos,u);
    else update(2*at+1,mid,R,pos,u);

    tree[at]=tree[2*at]+tree[2*at+1];
}

int query(int at,int L,int R,int l,int r)
{
    if(L>r || R<l)return MAX;
    else if(L>=l && R<=r)return tree[at];

    int mid=(L+R)/2;
    int x=query(2*at,L,mid,l,r);
    int y=query(2*at+1,mid+1,R,l,r);

    return min(x,y);
}

int main()
{
    ll n,t,a,b,c,q,cases=0;
    cin>>t;
    while(t--){//printf("\n");
        scanf("%lld %lld",&n,&q);
        for(int i=1;i<=n;i++)scanf("%lld",&ar[i]);
        STB(1,1,n);
        printf("Case %lld:\n",++cases);
        for(int i=1;i<=q;i++){
            scanf("%lld %lld",&a,&b);
            printf("%d\n",query(1,1,n,a,b));
        }

    }

    return 0;
}
