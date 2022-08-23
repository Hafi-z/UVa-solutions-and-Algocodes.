#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100];
int visited[100];
//map<vector<pair<int,int>>v,int>m;

void bfs(int s,int n)
{
    for(int i=0;i<n;i++)visited[i]=0;
    queue<int>Q;
    Q.push(s);
    visited[s]=1;cout<<"->"<<s<<endl;///visited starting node.
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<adj[u].size();i++){

            if(visited[adj[u][i]]==0){
                int v=adj[u][i];
                visited[v]=1;
                cout<<"->"<<v<<endl;///visited nodes.
                Q.push(v);
            }
        }
    }
}

int main()
{
    //long long
    int n,e,a,b,c,D;
    cin>>n>>e;
    for(int i=0;i<n;i++)adj[i].clear();
    //for(int i=0;i<n;i++)visited[i]=0;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        adj[a].push_back(b);///a er shathe b connected.
        adj[b].push_back(a);///b er shathe a connected.
    }
    bfs(1,n);
    return 0;
}
