#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 2*acos(0.0)

bool Triplets(ll a,ll b,ll c)
{
    if(a<=0 || b<=0 || c<=0)return false;
    vector<ll>vec{a,b,c};
    sort(vec.begin(),vec.end());
    a=vec[0],b=vec[1],c=vec[2];
    if(a+b<=c)return false;
    ll p1=a,p2=c-b;
    ll div=__gcd(p1,p2);//cout<<div<<endl;
    p1/=div;p2/=div;
    ll q1=c+b,q2=a;
    div=__gcd(q1,q2);//cout<<div<<endl;
    q1/=div,q2/=div;
    return (p1==q1 && p2==q2);
}

int main()
{
    ll t,a,b,c,D,q,s=0,x4;
    //double n,m,e,x,x1,x2;
    //string s1,s2;
    //vector<ll>vec{a,b,c};
    cin>>t;
    for(int i=1;i<=t;i++){///source: GEEKSFORGEEKS.
        cin>>a>>b>>c;
    if(Triplets(a,b,c))cout<<"Case "<<i<<": yes\n";
    else cout<<"Case "<<i<<": yes\n";

    }

    return 0;
}
