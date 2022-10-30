#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;

ll m;
ll bigmod(ll b,ll p,ll MOD)
{
    //if(b==mod)MOD+=1;
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

vector<int>prime(100001,0);
vector<int>mark(100001,0);
int nprime;

void sieve(int n)///FINDING PRIME
{
    int limit=sqrt(n*1.0)+1,s=0;nprime=0;
    mark[1]=1;///1 if not prime.
    mark[2]=0;prime[nprime++]=2;//cout<<2<<endl;
    //for(int i=4;i<=n;i+=2)mark[i]=1;
    for(int i=3;i<=n;i+=2){
        if(!mark[i]){prime[nprime++]=i;//cout<<i<<endl;
        if(i<=limit){///karon limit er upor theke n porjonto not prime gula already cuta hoise.
            for(int j=i*i;j<=n;j+=i*2){
                mark[j]=1;
            }
        }}
    }
}

ll nod(ll n)///Number of divisors
{
    ll nod=1,x3=0,x,y,z;
    ll sqrtN=sqrt(n)+1;
    for(int i=0;prime[i]<=sqrtN&&i<nprime;i++){
        if(n==1)break;
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n/=prime[i];
                x3++;
            }//cout<<prime[i]<<" "<<x3<<endl;
            x=bigmod(prime[i],(x3*m)+1,mod);
            x-=1;if(x<0)x+=mod;
            y=bigmod(prime[i]-1,mod-2,mod);
            //y-=1;
            z=((x%mod)*(y%mod))%mod;
            nod=((nod%mod)*(z%mod))%mod;
            x3=0;
        }
    }
    if(n>1){
        x=bigmod(n,m+1,mod);
        x-=1;if(x<0)x+=mod;
        y=bigmod(n-1,mod-2,mod);
        //y-=1;
        z=((x%mod)*(y%mod))%mod;
        nod=((nod%mod)*(z%mod))%mod;
    }

    return nod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(sqrt(INT_MAX));
    ll t,c=0;
    cin>>t;
    while(t--){
        ll n;
        cin>>n>>m;
        ll x,y,z;
        x=nod(n);
        printf("Case %lld: %lld\n",++c,x);
    }
}

