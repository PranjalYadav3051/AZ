#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M 1e9+7

#define pb push_back
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define all(x) (x).begin(), (x).end()
#define ll             long long
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            ll x; cin>>x; while(x--)
#define google cout << "Case #" << test_num << ": "
#define hi(x)           cout<<"hi"<<x<<endl;
#define ACC(v)          accumulate(v.begin(),v.end(),0ll)

#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define pr(...){}
#define debarr(a,n){}
#define debmat(mat,row,col){}
#endif

ll n;
ll x[101];

//O(S*(1+T))
// INITALLY ALL THE TYPE OF SUM WAS COMPUTED AND THEN REST OF THE Q VALUES WERE ANSWERED IN O(1)
// N ->100
// X -> 100000
// Q -> 100000
// Y-> 100000


ll dp[101][100100];

bool rec(ll level, ll sneed)
{
    //pruning
    if(sneed < 0)
    {
        return false;
    }

    // base case
    if(level == n)
    {
        if(sneed == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //cache check
    if(dp[level][sneed] != -1)
    {
        return dp[level][sneed];
    }

    // transition
    bool ans = rec(level + 1, sneed - x[level]) || rec(level + 1, sneed);

    // save and return
    return dp[level][sneed] = ans;
}

void solve()
{
 cin >> n;
 for(ll i = 0; i < n; i++)
 {
     cin >> x[i];
 }
 ll q;
    cin >> q;
    while(q--)
    {
        ll sneed;
        cin >> sneed;
        memset(dp, -1, sizeof(dp));
        if(rec(0, sneed))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}

int32_t main()
{
  fast;
  #ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  w(t)
  solve();
  
}
 

