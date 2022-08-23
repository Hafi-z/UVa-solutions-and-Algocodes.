#include<bits/stdc++.h>

#define ll long long
#define debug(x) cout<<":["<<x<<"DE]"<<endl;
#define debug2(x,y) cout<<"["<<x<<" "<<y<<"DE]"<<endl;

using namespace std;

pair<ll,pair<ll,ll>>p[101];
ll l1[101],sz[101],nodes,edges;
map<ll,ll>mp;///for mapping values with actual algorithm values(index values).

void initialize()
{
    for(int i=0;i<100;i++)l1[i]=i,sz[i]=1;
}

ll root(ll a)
{
    while(l1[a]!=a)a=l1[a];
    return a;
}

void unionn(ll a,ll b)
{
    ll root_a=root(a);
    ll root_b=root(b);
    if(sz[root_a]>sz[root_b]){
        l1[b]=l1[root_a];
        sz[a]+=sz[b];
    }
    else{
        l1[a]=l1[root_b];
        sz[b]+=sz[a];
    }
}

bool findd(ll a,ll b)
{
    if(root(a)==root(b))return true;
    return false;
}

ll kruskal()
{
    ll x,y,mcost=0,cost;
    for(int i=0;i<edges;i++){
        x=p[i].second.first;
        y=p[i].second.second;
        cost=p[i].first;
        if(!findd(x,y)){
            mcost+=cost;
            unionn(x,y);
        }
    }
    return mcost;
}

int main()///Complexity: O(edges log(nodes)).
{
    initialize();

    cin>>nodes>>edges;
    ll weight,x,y;
    for(int i=0;i<edges;i++){
        cin>>x>>y>>weight;
        p[i]={weight,{x,y}};
    }
    sort(p,p+edges);
    ll mincost=kruskal();
    cout<<mincost;
}
