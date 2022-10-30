#include<iostream>
#include<cstdio>
#include<string>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int>adj[201];
int visited[201];
int b=5,r=3;

//int bfs(int s,int n)
//{
//    for(int i=0;i<n;i++)visited[i]=0;
//    queue<int>Q;
//    Q.push(s);
//    visited[s]=1;//cout<<s<<"->"<<visited[s]<<endl;
//    while(!Q.empty()){
//        int u=Q.front();
//        Q.pop();
//        for(int i=0;i<adj[u].size();i++){
//                if(visited[u]==visited[adj[u][i]])return 0;
//            else if(visited[adj[u][i]]==0){
//                int v=adj[u][i];
//                if(visited[u]==r)
//                    visited[v]=b;
//                //cout<<v<<endl;
//                else visited[v]=r;
//
//                //cout<<v<<"->"<<visited[v]<<endl;
//                Q.push(v);
//            }
//        }
//    }
//    return 1;
//}

int main()
{
    //long long
    ll t,n,e,a[101],b,c,D,q,s=0,x,x1=1,j;
    //string s;
    //queue<int>Q;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        j=ceil(sqrt(n));//n numberta jekhane ase tar (n*n)th
        //index ta ber korar jonno formula.
        //j+=1;
        //m=k*k-k+1;
                x=(j-1)*j+1;//(n*n) index er value ta ber korar formula.
                if(x==n){cout<<"Case "<<i<<": "<<j<<" "<<j<<endl;}
                else if(j%2==0 && n>x){
                    cout<<"Case "<<i<<": "<<j<<" "<<j-abs(n-x)<<endl;
                }
                else if(j%2!=0 && n>x){
                    cout<<"Case "<<i<<": "<<j-abs(n-x)<<" "<<j<<endl;
                }
                else if(j%2==0 && n<x){
                    cout<<"Case "<<i<<": "<<j-abs(n-x)<<" "<<j<<endl;
                }
                else if(j%2!=0 && n<x){
                    cout<<"Case "<<i<<": "<<j<<" "<<j-abs(n-x)<<endl;
                }

        }
    //queue<int>Q;
    //Q.push(s);

    return 0;
}

