#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007
#define mod2 998244353
#define maxx 200005

string s,s2;ll k,n;

struct node
{
    bool endmark;
    node* next[26+1];
    node(){
        endmark=false;
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
    }
}*root;

void insert(string str, int len)
{
    node* curr=root;
    for(int i=0;i<len;i++){
        int id=str[i]-'a';
        if(curr->next[id]==NULL)curr->next[id]=new node();
        curr=curr->next[id];
    }
    curr->endmark=true;
}

bool search(string str, int len)
{
    node* curr=root;
    for(int i=0;i<len;i++){
        int id=str[i]-'a';
        if(curr->next[id]==NULL)return false;
        curr=curr->next[id];
    }
    return curr->endmark;
}

void del(node* cur)
{
    for(int i=0;i<26;i++){
        if(cur->next[i])del(cur->next[i]);
    }
    delete(cur);
}
ll ans=0;
void dfs(node* cur,ll cnt)
{//debug(cnt)
    if(cur!=root&&cnt<=k)ans++;
    for(int i=0;i<26;i++){
        if(cur->next[i]!=NULL){
            if(s2[i]-'0'==0)dfs(cur->next[i],cnt+1);
            else dfs(cur->next[i],cnt);
        }
    }
}

int main()///https://codeforces.com/contest/271/problem/D
{_
    ll t=1,ca=1;
    //cin>>t;
    while(t--){
        root=new node();
        cin>>s>>s2>>k;
        n=s.size();
        for(int i=n-1;i>=0;i--){
            string s3=s.substr(i,n-i);
            insert(s3,s3.size());
        }
        dfs(root,0);
        cout<<ans;
    }
}

