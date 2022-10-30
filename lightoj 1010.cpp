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
        cin>>m>>n;
        if(m==1||n==1){cout<<"Case "<<i<<": "<<max(m,n)<<endl;}
        else if(m==2||n==2){
                if(max(m,n)%4==1 || max(m,n)%4==3)x=1;
                else if(max(m,n)%4==2)x=2;
                else if(max(m,n)%4==0)x=0;
                cout<<"Case "<<i<<": "<<max(m,n)+x<<endl;}
        else{//same color er ghor gulate maximum knights boshte parbe
                if((m*n)%2!=0)x=(m*n/2)+1;
        else x=m*n/2;
            cout<<"Case "<<i<<": "<<x<<endl;
        }
    }
    //queue<int>Q;
    //Q.push(s);

    return 0;
}
