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

void solve()
{
  ll n;
  cin >> n;
  vector<string> path(2);
  vector<vector<ll>> vec(2,vector<ll> (n,0));

  cin >> path[0];
  cin >> path[1];

  for (ll i = 0; i < n;i++)
  {
    if(path[0][i]=='1'||path[0][i]=='2')
      path[0][i] = '1';
    else
      path[0][i] = '3';
  }

  for (ll i = 0; i < n;i++)
  {
    if(path[1][i]=='1'||path[1][i]=='2')
      path[1][i] = '1';
    else
      path[1][i] = '3';
  }

  vec[0][0] = 1;
  if(path[0][0]==3 && path[1][0]==3)
    vec[1][0] = 1;

  for (ll i = 1; i < n-1;i++)
  {
    if(path[1][i-1]==1 && path[1][i]==1 || path[1][i]==1 && path[1][i+1]==3 || path[1][i]==3 && path[1][i+1]==1 || path[0][i]==3 && path[1][i]==3)
    {
      vec[1][i] = 1;
    }

    if(path[0][i-1]==1 && path[0][i]==1 || path[0][i-1]==1 && path[0][i]==3 || path[0][i]==3 && path[1][i]==3)
    {
      vec[0][i] = 1;
    }
    
  }

  pr(vec);
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
 

