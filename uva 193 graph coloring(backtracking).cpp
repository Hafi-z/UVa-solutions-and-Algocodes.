#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<x<<"DE\n";
#define debug2(x,y) cout<<x<<" "<<y<<"DE\n";

ll n,m,ans;
vector<ll>v;
//bitset<110>colored;
map<ll,ll>color,vis;
vector<ll>adj[110];

void backtrk(ll u)
{
    if(u==n+1){
        ll b=0;
        for(int i=1;i<=n;i++){
            if(color[i]==1)b++;
        }
        if(b>ans){
            ans=b;v.clear();
            for(int i=1;i<=n;i++){
                if(color[i])v.push_back(i);
            }
        }
        return;
    }

    bool ok=true;
    for(int j=0;j<adj[u].size();j++){
        if(vis[adj[u][j]]&&color[adj[u][j]]){
            ok=false;break;
        }
    }

    //colored.set(u);
    vis[u]=1;
    if(ok){
        color[u]=1;
        backtrk(u+1);
    }
    color[u]=0;
    backtrk(u+1);
    //colored.reset(u);
    vis[u]=0;
}

int main()///AC///By taking help of one github code.
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--){

        cin>>n>>m;ans=-1;
        for(int i=1;i<=n;i++){adj[i].clear();vis[i]=0,color[i]=0;}
        for(int i=1;i<=m;i++){
            ll a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        //colored.reset();
        ///1 for black
        ///0 for white
        backtrk(1);
        cout<<v.size()<<endl;
        for(int i=0;i<v.size()-1;i++)cout<<v[i]<<" ";
        cout<<v[v.size()-1]<<endl;
    }
}

