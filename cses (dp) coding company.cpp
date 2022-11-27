// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pint pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define CC(x) cout << "Case " << ++x << ":";
#define nn "\n"
#define LL_INF (1int << 62)
#define INF (1 << 30)
#define SetBit(x, k) (x |= (1int << k))
#define ClearBit(x, k) (x &= ~(1int << k))
#define CheckBit(x, k) ((x>>k)&1)
#define mod 1000000007
#define N 10005

int n, x;
int a[100];
int dp[101][101][5005];

// pos = current indeex
// active = number of active group
// sum = sum of penalties
ll solve(int pos, int active, int sum){
    if(sum>x) return 0; // if sum of penalty greater than x, the way is invalid
    if(pos==n-1){ // at the last index
        if(active==0 || active==1) return 1; // if active group count is 1, end that group at current index. if active group count is 0, the current element itself forms a group.
        else return 0;
    }

    if(dp[pos][active][sum]!=-1) return dp[pos][active][sum];

    ll res = 0;
    res = (res+solve(pos+1, active+1, sum+(a[pos+1]-a[pos])*(active+1)))%mod; // starting a new group from current index
    res = (res+solve(pos+1, active, sum+(a[pos+1]-a[pos])*active))%mod; // forming a group consisting only one element of the current index
    res = (res+active*solve(pos+1, active, sum+(a[pos+1]-a[pos])*active))%mod; // including current element to any of the existing active group
    if(active) res = (res+active*solve(pos+1, active-1, sum+(a[pos+1]-a[pos])*(active-1)))%mod; // if at least one active group, ending any existing group with the current element

    return dp[pos][active][sum] = res;
}

int main(){///https://cses.fi/problemset/task/1665/
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    memset(dp, -1, sizeof dp);

    cout << solve(0, 0, 0) << nn;

    return 0;
}

