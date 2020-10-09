#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<x<<"DE\n";
#define debug2(x,y) cout<<x<<" "<<y<<"DE\n";

string s,s2;ll c=1;
ll dp[105][105];
///Recursive dp.
ll lcs(ll idxs1, ll idxs2)
{
    if(idxs1==s.size()||idxs2==s2.size())return 0;
    if(s[idxs1]==s2[idxs2])return lcs(idxs1+1,idxs2+1)+1;
    if(dp[idxs1][idxs2]!=-1)return dp[idxs1][idxs2];

    ll choice1=lcs(idxs1+1,idxs2);
    ll choice2=lcs(idxs1,idxs2+1);

    return dp[idxs1][idxs2]=max(choice1,choice2);
}

///Iterative dp.
//ll lcs()
//{
//    for(int i=1;i<=s.size();i++){
//        for(int j=1;j<=s2.size();j++){
//            if(s[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1;
//            else if(dp[i-1][j]>=dp[i][j-1])dp[i][j]=dp[i-1][j];
//            else dp[i][j]=dp[i][j-1];
//        }
//    }
//    return dp[s.size()][s2.size()];
//}

int main()
{
    while(1){
        getline(cin,s);
        if(s=="#")break;
        getline(cin,s2);
        ///for iterative dp the following 1 line dp[i][j] will be equal to 0.
        for(int i=0;i<=100;i++)for(int j=0;j<=100;j++)dp[i][j]=-1;
        ll x;
        x=lcs(0,0);
        printf("Case #%lld: you can visit at most %lld cities.\n",c++,x);
    }
}

