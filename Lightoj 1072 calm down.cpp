#include<bits/stdc++.h>
#define ll long long int
#include <stdlib.h>
#include <vector>
#define pi acos(-1)
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

//vector<int>prime(8000000,0);
vector<bool>mark(100000000,false);
int prime[8000000];
int nprime;

void sieve(int n)
{
    int limit=sqrt(n*1.0)+1,s=0;nprime=0;
    mark[1]=true;///1 if not prime.
    mark[2]=false;prime[nprime++]=2;//cout<<2<<endl;
    for(int i=4;i<=n;i+=2)mark[i]=true;
    for(int i=3;i<=n;i+=2){
        if(!mark[i]){prime[nprime++]=i;//cout<<i<<endl;
        if(i<=limit){///karon limit er upor theke n porjonto not prime gula already cuta hoise.
            for(int j=i*i;j<=n;j+=i*2){
                mark[j]=true;
            }
          }
        }
    }
    //puts("2");
    //cout<<nprime<<endl;
    for(int i=1;i<=nprime;i+=100)cout<<prime[i-1]<<endl;
    //return nprime;
}
ll l1[200005],l2[100005],vis[100005],s=0,m;
ll dx[]={1,0,-1,0};
ll dy[]={0,-1,0,1};

ll arr[200005];
ll tree[200005];

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

vector<ll>v[5];
set<ll>v2;
map<ll,ll>m2;
vector<pair<ll,ll>>p2;

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

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t,i,q,n,m,k,l,c,d,p,nl,np,a,e=1,b,x2=-1,x1=1000000005,x3=0,x4=0,x5=0,x6=0,x8=0;
    double x10;char x11;int x12=0;
    string s2,s3="",s4,s5,s6,s7;
    queue<ll>q2;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>x10>>n;
        printf("Case %d: ",i);
        double xx=pi/n;
        double xxx=sin(xx);
        double xxxx=(x10*xxx)/(1+xxx);
        //cout<<(x10*xxx)/(xxxx)<<endl;
        printf("%.6f\n",xxxx);
    }

    return 0;
}
