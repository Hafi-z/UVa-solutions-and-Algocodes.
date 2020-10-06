#include<bits/stdc++.h>

#define ll long long
#define debug(x) cout<<x<<"DE"<<endl;

using namespace std;

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    string s,s2;
    while(cin>>s>>s2){
        if(s2.size()>s.size())swap(s,s2);
        reverse(s.begin(),s.end());
        reverse(s2.begin(),s2.end());

        vector<vector<ll>>mid((ll)252,vector<ll>((ll)502,0));
        vector<ll>ans((ll)502,0);

        ll c=0,d;
        for(int i=0;i<s2.size();i++){
            for(int j=0;j<s.size();j++){
                ll a=(s2[i]-'0')*(s[j]-'0');
                ll b=(a+c)%10;
                if((a+c)>9)c=(a+c-b)/10;
                else c=0;
                mid[i+1][j+1+i]=b;//debug(mid[i+1][j+1+i])
            }
            if(c>0)mid[i+1][s.size()+1+i]=c,c=0;
            //cout<<"EKTA SHESH\n";
        }
//        for(int i=1;i<=9;i++){
//            for(int j=1;j<=32;j++)cout<<mid[i][j];
//            cout<<endl;
//        }
        c=0;
        for(int i=1;i<=501;i++){ll y=0;
            for(int j=1;j<=s2.size();j++){
                y+=mid[j][i];
            }
            ans[i]+=(y+c)%10;
            if(y+c>9)c=(y+c-((y+c)%10))/10;
            else c=0;
        }
        ll x=0;
        for(int i=501;i>=1;i--){
            if(ans[i]!=0)x=1;
            if(x==1)cout<<ans[i];
        }
        if(x==0)cout<<0;
        cout<<endl;
    }
}

