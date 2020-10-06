#include<bits/stdc++.h>

#define ll long long
#define debug(x) cout<<":["<<x<<"DE]"<<endl;
#define debug2(x,y) cout<<"["<<x<<" "<<y<<"DE]"<<endl;

using namespace std;

map<pair<ll,ll>,ll>mp;
map<string,ll>mp2;
vector<ll>adj[2005];

ll prims_mst(ll source_node)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;

    q.push({0,source_node});

    vector<bool>selected(2005,false);

    ll mst_cost=0;

    while(!q.empty()){
        pair<ll,ll>item;
        item=q.top();
        q.pop();

        ll node=item.second,cost=item.first;

        if(!selected[node]){
            mst_cost+=cost;
            selected[node]=true;

            for(int i=0;i<adj[node].size();i++){
                if(!selected[adj[node][i]])q.push({mp[{node,adj[node][i]}],adj[node][i]});
            }
        }
    }
    return mst_cost;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ll t;
    cin>>t;
    for(int k=1;k<=t;k++){
        //cout<<endl;
        ll n,m,cn=0;
        cin>>m>>n;
        for(int i=1;i<=m;i++)adj[i].clear();
        string a,b;ll c;
        for(int i=1;i<=n;i++){
            cin>>a>>b>>c;
            if(!mp2[a])mp2[a]=++cn;
            if(!mp2[b])mp2[b]=++cn;
            adj[mp2[a]].push_back(mp2[b]);
            adj[mp2[b]].push_back(mp2[a]);
            mp[{mp2[a],mp2[b]}]=c;
            mp[{mp2[b],mp2[a]}]=c;
        }
        if(t==k)cout<<prims_mst(1)<<endl;
        else cout<<prims_mst(1)<<endl<<endl;
        mp2.clear();
    }
}

