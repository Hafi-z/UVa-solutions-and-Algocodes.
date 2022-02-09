#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007
#define mod2 998244353

ll n,m,ids[200005],x,y,ans,ans2=1,lowlink[200005],a[200005],node_id;
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

    ll popped_item=0;x=INT_MAX,y=0;
    if(lowlink[u]==ids[u]){
        while(stk.top()!=u){
            popped_item=stk.top();
            //cout<<popped_item<<" ";
            if(a[popped_item]<x)x=a[popped_item],y=1;
            else if(a[popped_item]==x)y+=1;
            stk_item[popped_item]=false;
            stk.pop();
        }
        popped_item=stk.top();
        //cout<<popped_item<<endl;
        if(a[popped_item]<x)x=a[popped_item],y=1;
        else if(a[popped_item]==x)y+=1;
        stk_item[popped_item]=false;
        stk.pop();
        ans+=x,ans2=ans2*y%mod;
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

int main()
{_
    ll t=1,ca=1;
    //cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cin>>m;
        for(int i=1;i<=m;i++){
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            //adj[v].push_back(u);
        }
        strong_con_component();
        cout<<ans<<" "<<ans2;
    }
}

