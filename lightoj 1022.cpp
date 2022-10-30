#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 2*acos(0.0)

int main()
{
    ll t,n,m,e,a[101],b,c,D,q,s=0,x,x1=1;
    double r,x2;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>r;
        x2=r*r*(4-pi);
        cout<<"Case "<<i<<": "<<fixed<<setprecision(2)<<x2<<endl;//fixed dile scientific ashena
    }

    return 0;
}
