#include<bits/stdc++.h>

#define ll long long
#define debug(x) cout<<x<<"DE"<<endl;

using namespace std;

vector<int>adj[100];
int visited[100];
ll graph[51][51];
ll dist[51][51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll t,cases=0;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;

        memset(dist,0,sizeof dist);
        memset(graph,0,sizeof graph);

        for(int i=1;i<=m;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            graph[a][b]=c;
            graph[b][a]=c;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(graph[i][j]==0)dist[i][j]=1e18;
                else dist[i][j]=graph[i][j];
            }
        }

        ///Problem: https://www.facebook.com/codingcompetitions/hacker-cup/2019/round-1/problems/A
        ///Floyd-warshall starts here.
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
                }
            }
        }
        ///ends here.

        bool ok=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(graph[i][j]>0&&graph[i][j]!=dist[i][j]){
                    ok=false;break;
                }
            }
            if(!ok)break;
        }
        cout<<"Case #"<<++cases<<": ";
        if(!ok){cout<<"Impossible\n";continue;}
        else cout<<m<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(graph[i][j]==0);
                else {cout<<i<<" "<<j<<" "<<graph[i][j]<<endl;
                graph[j][i]=0;}
            }
        }
    }
}

