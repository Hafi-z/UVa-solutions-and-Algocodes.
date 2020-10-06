#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<x<<"DE\n";
#define debug2(x,y) cout<<x<<" "<<y<<"DE\n";

ll queen[10];///queen[i]=j means queen at jth row in ith column.
ll row[10],diagonal_right[20],diagonal_left[20],cnt;
ll a,b;

void nqueen(ll at, ll n=8)
{
    if(at>n&&queen[b]==a){
        if(cnt>=10)printf("%lld",cnt++);
        else if(cnt<10)printf(" %lld",cnt++);
        printf("     ");
        for(int i=1;i<n;i++)cout<<" "<<queen[i];
        cout<<" "<<queen[n]<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(row[i]||diagonal_right[i+at]||diagonal_left[n+i-at])continue;
        queen[at]=i;
        row[i]=diagonal_right[i+at]=diagonal_left[n+i-at]=1;
        nqueen(at+1,n);
        row[i]=diagonal_right[i+at]=diagonal_left[n+i-at]=0;
    }
}

int main()
{
///I did this with the help of Mahbubul Hasan's book at page-64's nqueen code.
    ll t;
    cin>>t;
    for(int j=1;j<=t;j++){

        cin>>a>>b;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");cnt=1;
        //queen[b]=a;
        //row[a]=diagonal_left[a+b]=diagonal_right[8+a-b]=1;
        nqueen(1);
        for(int i=1;i<=10;i++)row[i]=diagonal_left[i]=diagonal_right[i]=queen[i]=0;
        for(int i=11;i<=20;i++)diagonal_left[i]=diagonal_right[i]=0;
        if(j<t)cout<<endl;
    }
}

