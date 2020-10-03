#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

vector<int>adj[201];
int visited[201];
int b=5,r=3;

int bfs(int s,int n)
{
    for(int i=0;i<n;i++)visited[i]=0;
    queue<int>Q;
    Q.push(s);
    visited[s]=r;//cout<<s<<"->"<<visited[s]<<endl;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<adj[u].size();i++){
                if(visited[u]==visited[adj[u][i]])return 0;
            else if(visited[adj[u][i]]==0){
                int v=adj[u][i];
                if(visited[u]==r)
                    visited[v]=b;
                //cout<<v<<endl;
                else visited[v]=r;

                //cout<<v<<"->"<<visited[v]<<endl;
                Q.push(v);
            }
        }
    }
    return 1;
}

int main()
{
    //long long
    int n,e,a,b,c,D;
    while(1){
        //scanf("%d",&n);
        cin>>n;
            if(n==0)break;
        //scanf("%d",&e);
        cin>>e;
    for(int i=0;i<n;i++)adj[i].clear();
    //for(int i=0;i<n;i++)visited[i]=0;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    c=bfs(0,n);
    //cout<<c<<endl;
    if(c)cout<<"BICOLORABLE."<<endl;
    else cout<<"NOT BICOLORABLE."<<endl;
    }

    return 0;
}

