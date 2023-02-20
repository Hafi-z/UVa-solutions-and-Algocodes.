#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007
#define mod2 998244353
#define inf LLONG_MAX
#define yes cout << "YES\n"
#define yes2 cout << "Yes\n"
#define no cout << "NO\n"
#define no2 cout << "No\n"
#define forn2(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define forn(x,n) for(int i=x;i<=n;i++)

#define MAX 200005
int failure[MAX];

void build_failure_function(vector<ll> &pattern, int m) {
  failure[0] = 0;
  failure[1] = 0; //base case

  for(int i = 2; i <= m; i++) {  //i is length of the prefix we are dealing with
    // j is the index of the largest next partial match
    // (the largest suffix/prefix) of the string under index i - 1
    int j = failure[i - 1];
    while(true) {
      // check if the last character of prefix of length i "expands" the current "candidate"
      if(pattern[j] == pattern[i - 1]) {
        failure[i] = j + 1;
        break;
      }
      // if we cannot "expand" even the empty string
      if(j == 0) {
          failure[i] = 0;
          break;
      }
      // else go to the next best "candidate" partial match
      j = failure[j];
    }
  }
}

int kmp(vector<ll> &text, vector<ll> &pattern)
{
  int n = text.size();
  int m = pattern.size();
  int cnt=0;
  build_failure_function(pattern, m);

  int i = 0; // the initial state of the automaton is
         // the empty string

  int j = 0; // the first character of the text

  while(true) {
    if(j == n) {
        break; //reached the end of the text
    }

    // character matched
    if(text[j] == pattern[i]) {
      i++; // change the state of the automaton
      j++; // get the next character from the text
      if(i == m) {
          cnt++;
          i=failure[i];
      }
    } else {
        if (i == 0) {
            // if we reached the empty string and failed to
            // "expand" even it; we go to the next
            // character from the text, the state of the
            // automaton remains zero
            j++;
        }
        else {
             //we try to "expand" the next best (largest) match
            i = failure[i];
        }
    }
  }
  return cnt;
}

int main()
{_
//    freopen("feast.in", "r", stdin);
//    freopen("feast.out", "w", stdout);
    ll t=1,ca=1;
    //cin>>t;
    ///CHECK FROM HERE***
    while(t--){///https://codeforces.com/problemset/problem/471/D
        ll n,w;
        cin>>n>>w;
        vector<ll>a,b;
        forn(1,n)
        {
            ll c;
            cin>>c;
            a.push_back(c);
        }
        forn(1,w)
        {
            ll c;
            cin>>c;
            b.push_back(c);
        }
        if(w==1){
            cout<<n<<endl;
            return 0;
        }
        forn(0,n-2)
        {
            a[i]-=a[i+1];
        }
        forn(0,w-2)
        {
            b[i]-=b[i+1];
        }
        a.pop_back();
        b.pop_back();
        cout<<kmp(a,b)<<endl;
    }
}

