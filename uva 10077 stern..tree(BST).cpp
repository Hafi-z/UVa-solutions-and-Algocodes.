#include<bits/stdc++.h>

#define ll long long
#define debug(x) cout<<":["<<x<<"DE]"<<endl;
#define debug2(x,y) cout<<"["<<x<<" "<<y<<"DE]"<<endl;

using namespace std;

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll m,n;
    while(cin>>m>>n){
        if(m==1&&n==1)break;
        ll a=0,b=1,c=1,d=1,e=1,f=0;
        while(1){
            if(m==c&&n==d)break;
            if(m*d<n*c){
                cout<<"L";
                e=c,f=d,c=a+e,d=b+f;
            }
            else{
                cout<<"R";
                a=c,b=d,c=a+e,d=b+f;
            }
        }cout<<endl;
    }
}

