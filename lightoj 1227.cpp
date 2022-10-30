#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long

using namespace std;

int main()
{
    ll t,a[10000],b,n,p,q,k,s=0,s1=0,x1=0,j;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>p>>q;
        for( j=0;j<n;j++)cin>>a[j];
        for( j=0;j<n;j++){s+=a[j];//cout<<s<<endl;
            if(j+1<=p && s<=q)continue;
            else break;
        }
        printf("Case %d: %lld\n",i,j);s=0;
    }

    return 0;
}
