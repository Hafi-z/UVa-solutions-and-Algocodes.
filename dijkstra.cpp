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
vector<ll>d;

void dijkstra(ll s) {
    d.assign(n, INF);
    vector<bool> u(n, false);

    d[s] = 0;
    for (ll i = 0; i < n; i++) {
        ll v = -1;
        for (ll j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
            }
        }
    }
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
    }
}
