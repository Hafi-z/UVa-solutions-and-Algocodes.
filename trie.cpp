#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007
#define mod2 998244353
#define maxx 200005

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

int main()///http://www.shafaetsplanet.com/?p=1679
{_
    ll t=1,ca=1;
    //cin>>t;
    while(t--){
        cout<<"enter number of words ";
        root=new node();
        ll n;
        cin>>n;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            insert(s,s.size());
        }
        cout<<"enter number of queries ";
        ll q;
        cin>>q;
        for(int i=1;i<=q;i++){
            string s;
            cin>>s;
            if(search(s,s.size()))cout<<"found\n";
            else cout<<"not found\n";
        }
        del(root);
    }
}
