#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t,n,m,e,a[101],b,c,D,q,s=0,x,x1=1;
    //string s;
    //queue<int>Q;
    //printf("%d",ceil(10.5));
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>x;
            if(x>0)s+=x;
        }
        cout<<"Case "<<i<<": "<<s<<endl;s=0;
    }

    return 0;
}
