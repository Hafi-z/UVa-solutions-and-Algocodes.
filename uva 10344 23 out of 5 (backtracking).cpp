#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<x<<"DE\n";
#define debug2(x,y) cout<<x<<" "<<y<<"DE\n";

ll l1[6];
bool backtrack(ll i,ll res)
{
    if(i>5&&res==23)return true;
    else if(i>5)return false;

    return backtrack(i+1,res+l1[i])||backtrack(i+1,res-l1[i])||backtrack(i+1,res*l1[i]);
}

int main()
{
    ///I did this solution by the following link=>
    ///https://saicheems.wordpress.com/2013/08/06/uva-10344-23-out-of-5/
    while(1){
        ll s=0;
        for(int i=1;i<=5;i++){
            cin>>l1[i];s+=l1[i];
        }
        sort(l1+1,l1+6);bool ok=false;
        if(!s)break;
        do{
            if(backtrack(2,l1[1])){
                ok=true;break;
            }
        }while(next_permutation(l1+1,l1+6));
        if(ok)cout<<"Possible\n";
        else cout<<"Impossible\n";
    }
}

