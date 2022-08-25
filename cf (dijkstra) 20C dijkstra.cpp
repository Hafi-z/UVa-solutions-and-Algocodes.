#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007

const ll INF = 1e18;
ll n,m,ok=1;
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
        q.pop();//debug2(v.first,v.second)
        if(u[v.second])continue;
        u[v.second] = true;
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
    for(ll i=dest;i!=s;i=p[i]){
        if(i==-1){ok=0;break;}
        path.push_back(i);
    }
    path.push_back(s);
    reverse(path.begin(),path.end());
    return path;
}

int main()
{_
//    freopen("angry.in", "r", stdin);
//    freopen("angry.out", "w", stdout);
    ll t=1,ca=1;
    //cin>>t;
    while(t--){
        //ll n;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        dijkstra(1);
        vector<ll>ans=restore_path(1,n);
        if(!ok){
            cout<<-1;return 0;
        }
        for(auto i:ans)cout<<i<<" ";
    }
}

