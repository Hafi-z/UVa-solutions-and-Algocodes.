#include<bits/stdc++.h>

#define ll long long
#define debug(x) cout<<x<<"DE"<<endl;

using namespace std;

bool valid(int a,int b)
{
    if(a>=1&&a<=8&&b>=1&&b<=8)return true;
    else return false;
}

map<pair<ll,ll>,ll>visited,dist;
ll dir[8][2]={{-1,2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{1,-2}};
string s1,s2;

void bfs(pair<ll,ll>p)
{
    for(ll i=1;i<=8;i++)for(ll j=1;j<=8;j++)visited[{i,j}]=0,dist[{i,j}]=0;
    queue<pair<ll,ll>>Q;
    Q.push({p.first,p.second});
    visited[{p.first,p.second}]=1;

    while(!Q.empty()){
        pair<ll,ll>u=Q.front();
        Q.pop();
        for(int i=0;i<8;i++){
            ll x,y;
            x=u.first+dir[i][0];
            y=u.second+dir[i][1];
            if(valid(x,y)&&visited[{x,y}]==0){
                visited[{x,y}]=1;
                Q.push({x,y});
                dist[{x,y}]=dist[{u.first,u.second}]+1;
                if(x==(ll)(s2[1]-'0') && y==(ll)(s2[0]-'a'+1))return;
            }
        }
    }
}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while(cin>>s1>>s2){//debug(s1)
        bfs({(ll)(s1[1]-'0'),(ll)(s1[0]-'a'+1)});
        //printf("To get from %s to %s takes %lld knight moves.\n",s1,s2,dist[{(ll)(s2[1]-'0'),(ll)(s2[0]-'a'+1)}]);
        cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<dist[{(ll)(s2[1]-'0'),(ll)(s2[0]-'a'+1)}]<<" knight moves.\n";
    }
}

