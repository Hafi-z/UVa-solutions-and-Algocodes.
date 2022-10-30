#include<bits/stdc++.h>
#define ll long long int
#include <stdlib.h>
#include <vector>
#define pi acos(-1)
#define max 100005
#define pb push_back
#define MOD 1e9+7
#define highest(x) numeric_limits<x>::max()
#define lowest(x) numeric_limits<x>::min()
///s1.substr(1,3);///STARTING FROM INDEX 1, 3 LNEGTH SUBSTRING.
///s1.find("adn")///RETURNS STARTING INDEX OF THE SUBSTRING
///"adn" IF IT EXISTS IN THE STRING S1.///
///s1.find("adn",int pos);///RETURNS STARTING INDEX OF THE
///SUBSTRING "adn" SEARCHING FROM INDEX POS OF STRING s1.///
///string::npos returns a garbage value if not found...
///reverse(s1.begin(),s1.end())-> to reverse a string.
///next_permutation(f,f+n)->f array er next permutation return korbe..
///str.erase(1,2)->deletes 2 char from index 1..
///for(auto i:p2)->i=p2.begin() theke p2.end() er ag porjonto..
///max_element(v,v+4);->return a pointer to the max element
///in a array/vector.. v from 1st element to 4th element.
///same for min_element(v,v+4);
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define gcd(a,b) __gcd(a,b)
using namespace std;

ll l1[200005],l2[100005],vis[100005],s=0,m;
ll dx[]={1,0,-1,0};
ll dy[]={0,-1,0,1};

//ll arr[200005];
//ll tree[1000005];
//
//void update1(ll idx,ll val,ll n)
//{
//    while(idx<=n){
//        tree[idx]+=val;
//        idx+=(idx & -idx);
//    }
//}
//
//ll read(ll idx)
//{
//    ll sum=0;
//    while(idx>0){
//        sum+=tree[idx];
//        idx-=(idx & -idx);
//    }
//    return sum;
//}
//
//vector<ll>v[5];
//set<ll>v2;
//map<ll,ll>m2;
//vector<pair<ll,ll>>p2;

//void dfs(int a)
//{
//    if(vis[a])return;
//    vis[a]=1;
//    if(!v[a].size()){s++;return;}
//    for(int i=0;i<v[a].size();i++){
//        if(!vis[v[a][i]]&&l1[a]+l1[v[a][i]]<=m)dfs(v[a][i]);
//    }
//    //cout<<s<<endl;
//}
char s2[max];
//int sum[max];
int tree[max*4];
//int prop[max*3];
void STB(int at,int L,int R)
{
    //int sum[at]=0;
    if(L==R){
        tree[at]=(s2[L-1]-'0');
        return;
    }
    int mid=(L+R)/2;
    STB(2*at,L,mid);
    STB(2*at+1,mid+1,R);
    //tree[at]=tree[2*at]+tree[2*at+1];
    //return sum[at];
}

void update(int at,int L,int R,int pos1,int pos2)
{
    if(L>pos2 || R<pos1)return;

    if(L>=pos1 && R<=pos2){
        tree[at]++;
        return;
    }
    int mid=(L+R)>>1;
//    if(pos2<=mid)update((at<<1)+1,L,mid,pos1,pos2);
//    else if(pos1>mid)update((at<<1)+2,mid+1,R,pos1,pos2);
//    else{
//        update((at<<1)+1,L,mid,pos1,mid);
//        update((at<<1)+2,mid+1,R,mid+1,pos2);
//    }
    update((at<<1),L,mid,pos1,pos2);
    update((at<<1)+1,mid+1,R,pos1,pos2);
    //tree[at]=tree[(at<<1)+1]+tree[(at<<1)+2]+prop[at]*(R-L+1);
}

int query(int at,int L,int R,int l)
{
    //if(L<=l && l<=R)return tree[at];
    if(L==R)return tree[at];
    if(L>l && l>R)return 0;

    int mid=(L+R)>>1;
//    if(l<=mid)query((at<<1)+1,L,mid,l,carry+prop[at]);
//    else query((at<<1)+2,mid+1,R,l,carry+prop[at]);
    if(l<=mid)return tree[at]+query((at<<1),L,mid,l);
    else return tree[at]+query((at<<1)+1,mid+1,R,l);
    //return ;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t,i,q,n,m,k,l,cases=0,d,p,nl,np,a,e=1,b,x2=-1,x1=1000000005,x3=0,x4=0,x5=0,x6=0,x8=0;
    double x10;char x11;int x12=0;
    string s3,s4,s5,s6,s7;
    queue<ll>q2;
    //cin>>t;
    scanf("%lld",&t);
    while(t--){printf("Case %lld:\n",++cases);
        //cin>>s2;
        scanf("%s",s2);
        n=strlen(s2);
        //cin>>q;
        //STB(0,0,n-1);
        scanf("%lld",&q);
        for(int i=1;i<=q;i++){
            cin>>x11;
            //scanf("%c",&x11);
            //switch(x11){
            //case 'I':
            if(x11=='I'){
                scanf("%lld %lld",&a,&b);
                update(1,1,n,a,b);
            }
            else if(x11=='Q'){
                scanf("%lld",&a);
                //printf("%d\n",query(0,0,n-1,a-1));
                np=query(1,1,n,a);
                //cout<<np<<endl;
                if(np&1)printf("%d\n",1^(s2[a-1]-'0'));
                else printf("%d\n",0^(s2[a-1]-'0'));
            }
        }
        memset(tree,0,sizeof tree);
        //memset(prop,0,sizeof prop);
    }

    return 0;
}

