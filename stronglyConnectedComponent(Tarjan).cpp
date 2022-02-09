#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007
#define mod2 998244353

ll n,m,ids[200005],lowlink[200005],a[200005],node_id;
bool stk_item[200005];
stack<ll>stk;
vector<ll>adj[200005];

void find_component_dfs(ll u)
{
    ids[u]=lowlink[u]=++node_id;
    stk.push(u);
    stk_item[u]=true;

    for(auto v:adj[u]){
        if(ids[v]==-1){
            find_component_dfs(v);
            lowlink[u]=min(lowlink[u],lowlink[v]);
        }
        else if(stk_item[v])lowlink[u]=min(lowlink[u],lowlink[v]);
    }

    ll popped_item=0;
    if(lowlink[u]==ids[u]){
        while(stk.top()!=u){
            popped_item=stk.top();
            cout<<popped_item<<" ";
            stk_item[popped_item]=false;
            stk.pop();
        }
        popped_item=stk.top();
        cout<<popped_item<<endl;
        stk_item[popped_item]=false;
        stk.pop();
    }
}

void strong_con_component()
{
    for(int i=1;i<=n;i++){
        ids[i]=lowlink[i]=-1;
        stk_item[i]=false;
    }

    for(int i=1;i<=n;i++){
        if(ids[i]==-1){
            find_component_dfs(i);
        }
    }
}
///TARJAN'S ALGORITHM
///TUTOTIAL: https://www.youtube.com/watch?v=wUgWX0nc4NY&t=21s&ab_channel=WilliamFiset
///CODE: https://www.topcoder.com/thrive/articles/tarjans-algorithm-for-strongly-connected-components
int main()
{_
    ll t=1,ca=1;
    //cin>>t;
    while(t--){
        cin>>n;
        cin>>m;
        for(int i=1;i<=m;i++){
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            //adj[v].push_back(u);
        }///PRINTING SCCs
        strong_con_component();
    }
}

