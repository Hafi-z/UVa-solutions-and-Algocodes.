#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<x<<"DE\n";
#define debug2(x,y) cout<<x<<" "<<y<<"DE\n";
#define MOD 1000000007

vector<int>prime(50000005,0);
vector<int>mark(3125005,0);
int nprime;
map<ll,ll>mp;

void sieve(int n)///FINDING PRIME
{
    int limit=sqrt(n*1.0)+1,s=0;nprime=0;
    ///mark[1]=1;///1 if not prime.
    prime[nprime++]=2;mp[2]=1;
    //for(int i=4;i<=n;i+=2)mark[i]=1;
    for(int i=3;i<=n;i+=2){
        if(!(mark[i>>5]&(1<<(i&31)))){prime[nprime++]=i;mp[i]=1;
            if(i<=limit){///karon limit er upor theke n porjonto not prime gula already cuta hoise.
                for(int j=i*i;j<=n;j+=i*2){
                    mark[j>>5]|=(1<<(j&31));
                }
            }
        }
    }
}

int main()
{
    sieve(10000000);

    ll n;
    while(cin>>n){
        if(n<=7){
            cout<<"Impossible.\n";continue;
        }
        else if(n&1){
            cout<<"2 3 ";n-=5;
        }
        else {cout<<"2 2 ";n-=4;}
        if(mp[n-2]){
            cout<<"2 "<<n-2<<endl;continue;
        }
        for(int i=3;i<=n;i+=2){
            if(mp[i]&&mp[n-i]){
                cout<<i<<" "<<n-i<<endl;break;
            }
        }
    }
}

