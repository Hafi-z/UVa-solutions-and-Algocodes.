#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<x<<"DE\n";
#define debug2(x,y) cout<<x<<" "<<y<<"DE\n";

int main()
{
    ll a,b;
    while(cin>>a>>b){
        string s,s2;
        for(int i=1;i<=32;i++){
            if(a%2)s+='1';
            else s+='0';
            a/=2;
            if(b%2)s2+='1';
            else s2+='0';
            b/=2;
        }
//        reverse(s.begin(),s.end());
//        reverse(s2.begin(),s2.end());
        string s3;ll x=0,y=1;
        for(int i=0;i<32;i++){
            if(s[i]==s2[i])s3+='0';
            else s3+='1',x+=y;
            y*=2;
        }
        cout<<x<<endl;
    }
}

