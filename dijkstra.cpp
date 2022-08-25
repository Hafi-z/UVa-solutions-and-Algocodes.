#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007

const ll INF = 1e18;
ll n;
vector<pair<ll,ll>> adj[1000000];
vector<ll>d,p;

void dijkstra(ll s) {
    d.assign(n+1, INF);
    p.assign(n+1, -1);
    vector<bool> u(n, false);

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
    q.push({0,s});
    d[s] = 0;
    while(!q.empty()){
        pair<ll,ll> v=q.top();
        q.pop();//debug(v.second)
        if(u[v.second])continue;
        u[v.second] = true;
        if(d[v.second]==INF)break;
        for (auto edge : adj[v.second]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v.second] + len < d[to]) {
                d[to] = d[v.second] + len;
                p[to]=v.second;
                q.push({d[to],to});
            }
        }
    }
}

vector<ll>restore_path(ll s, ll dest)
{
    vector<ll>path;
    for(ll i=dest;i!=s;i=p[i])path.push_back(i);
    path.push_back(s);
    reverse(path.begin(),path.end());
    return path;
}

///directed graph below, (works for undirected also)
/*
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
5 4 2
5 6 5
4 6 1
*/

///tutorial: https://www.youtube.com/watch?v=XB4MIexjvY0&ab_channel=AbdulBari
///code: https://cp-algorithms.com/graph/dijkstra.html

///complexity: O(nlogn)
///doesn't work for negative weight
int main()
{_
    ll t=1,ca=1;
    //cin>>t;
    while(t--){
        ll m;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            ll a,b,w;
            cin>>a>>b>>w;
            adj[a].push_back({b,w});
        }
        dijkstra(1);
        for(int i=1;i<=n;i++){
            debug2(i,d[i])
        }
        ///shortest path finding from source to destination
        vector<ll>ans=restore_path(1,n);
        for(auto i:ans)debug(i)
    }
}
