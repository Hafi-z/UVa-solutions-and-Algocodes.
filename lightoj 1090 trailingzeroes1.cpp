#include<bits/stdc++.h>
#include<sstream>
#include<chrono>
#define ll long long int
#include <stdlib.h>
#include <vector>
#define pi acos(-1)
#define maxm 100005
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
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
///__builtin_popcount(a);->counts how many number of one's
/// in a in binary representation.
///accumulate(l1+1,l1+10+1,0LL)=>it perform the sum from l1[1] to
///l1[10] and 0 is the initial sum.
///cout<<fixed<<setprecision(12)<<x14<<endl;//=>x14 er
///doshomik er por 12 ta 0 thakbe.
///sort()=>[startaddress,endaddress).
///    time_t now=time(0);
///    char* dt=ctime(&now);
///    cout<<dt<<endl;
///above 3 lines code is for system time representing.///
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define gcd(a,b) __gcd(a,b)
using namespace std;
using namespace std::chrono;

ll l1[200005],vis[200005],l3[1000005],s=0,m=0,mn=0;
ll dx[]={1,0,-1,0};
ll dy[]={0,-1,0,1};

char s2[maxm];
//int sum[max];
int tree[maxm*4];
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
        tree[at]^=1;
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
    if(l<=mid)return tree[at]^query((at<<1),L,mid,l);
    else return tree[at]^query((at<<1)+1,mid+1,R,l);
    //return ;
}

///reverse sorting function.
bool revp(const pair<ll,ll>&a,const pair<ll,ll>&b){
    if(a.first!=b.first)return a.first>b.first;
    else return a.second<b.second;
}
bool revp2(const pair<ll,ll>&a,const pair<ll,ll>&b){return a.second<b.second;}
bool revp3(const pair<ll,ll>&a,const pair<ll,ll>&b){return a.first>b.first;}

ll bigmod(ll b,ll p)
{
    ll an=1;b%=MOD;
    while(p>0){
        if(p&1)an=an*b%MOD;
        b=b*b%MOD;
        p>>=1;
    }
    return an;
    ///BINARY EXPONENTATION///
    ///TAKEN FROM "e-maxx"///
}

vector<int>prime(1000001,0);
//vector<int>prime1(1000001,0);
vector<int>mark(1000001,0);
int nprime;

void sieve(int n)
{
    int limit=sqrt(n*1.0)+1,s=0;nprime=0;
    mark[1]=1;///1 if not prime.
    mark[2]=0;prime[nprime++]=2;//cout<<2<<endl;
    for(int i=4;i<=n;i+=2)mark[i]=1;
    for(int i=3;i<=n;i+=2){
        if(!mark[i]){prime[nprime++]=i;//cout<<i<<endl;
        if(i<=limit){///karon limit er upor theke n porjonto not prime gula already cuta hoise.
            for(int j=i*i;j<=n;j+=i*2){
                mark[j]=1;
            }
        }}
    }
}

ll nod(ll n)
{
    ll listi[1001],listsize=0,nod=1,x3=0,x=0,y=0;
    ll sqrtN=sqrt(n)+1;
    for(int i=0;prime[i]<=sqrtN;i++){
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n/=prime[i];
                listi[listsize++]=prime[i];x3++;
            }
            if(prime[i]==5)x=x3;
            else if(prime[i]==2)y=x3;
            x3=0;
        }
        if(i==2)break;
    }
    //if(!mark[n])nod++;
    return min(x,y);
}

vector<ll>vp2[200005];

int findTrailingZeros5(int n)
{
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;

    return count;
}
int findTrailingZeros2(int n)
{
    int count = 0;
    for (int i = 2; n / i >= 1; i *= 2)
        count += n / i;

    return count;
}

int main()///Hafiz///ICE 6th///
{
    //IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t,i=1,j,k,y,x,e,n,c,m,z,z2,l,r,cases=0,d,p,nl,np,a,b,x2=-1,x1=1000000005,x3=0,x4=0,x5=0,x6=0,x7=0,x8=0;
    double x10=100000,x14,x15,x16,x17,x18;char x11,y1='a',y2,y3;int x12=0;
    string s3[11],s4,s5,s6,s7,s8;
    queue<ll>q2;
    stack<ll>st;
    set<ll>y4;
    vector<ll>vp;
    //vector<ll>vp2[200005];
    //map<ll,ll>mp;
    map<ll,ll>m2;
    map<ll,ll>::iterator it;
    map<ll,ll>m3;

    cin>>t;
    while(t--){
        ll cot=0,cof=0,mx=0,my=0,mz=0,mz2=0,mc5=0,mc2=0,dc5=0,dc2=0,zc5=0,zc2=0;m=0;d=0;z=0;z2=0;k=0;
        //cin>>n>>a>>b>>c;
        scanf("%lld %lld %lld %lld",&n,&a,&b,&c);
        mc5=findTrailingZeros5(n);
        mc2=findTrailingZeros2(n);
        //cout<<mc5<<" "<<mc2<<endl;
        dc5=findTrailingZeros5(a);
        dc2=findTrailingZeros2(a);
        //cout<<dc5<<" "<<dc2<<endl;
        zc5=findTrailingZeros5(n-a);
        zc2=findTrailingZeros2(n-a);
        //cout<<zc5<<" "<<zc2<<endl;
        //z2=d+z;
        //cout<<z2<<endl;

        while(b%2==0&&b>0){
            b/=2;
            cot++;
        }//cout<<cot<<endl;
        while(b%5==0&&b>0){
            b/=5;
            cof++;
        }//cout<<cof<<endl;
        //k=(ll)((ll)min(cot,cof)*(ll)c);
        //cout<<k<<endl;
        mx=mc5+(ll)(cof*c);my=mc2+(ll)(c*cot);
        mz=dc5+zc5;mz2=dc2+zc2;
        mx=min(mx-mz,my-mz2);
        //mz=min(mz,mz2);
        //cout<<cof<<" "<<cot<<endl;
        if(mx>=0){
            //m-=z2;
            printf("Case %lld: %lld\n",++cases,(ll)(mx));
        }
        else{
            //z2-=m;
            //if((ll)(k-z2)>=0)printf("Case %lld: %lld\n",++cases,(ll)(k-z2));
            printf("Case %lld: 0\n",++cases);
        }

        //printf("Case %lld: %lld\n",++cases,(ll)(m+e));
    }

    return 0;
}

