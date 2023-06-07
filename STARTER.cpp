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


ll  gcd(ll m, ll n)
{
    if(n == 0) return m;

    return gcd(n, m % n);
}

ll extended_euclid(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }
  ll x1, y1;
  ll d = extended_euclid(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

ll inverse(ll a, ll m) {
  ll x, y;
  ll g = extended_euclid(a, m, x, y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}

ll power(ll x,ll n)
{   ll result=1;
    while(n>0)
        {   if(n % 2 ==1)
            result=(result * x)%M;
            x=(x*x)%M;
            n=n/2;
        }
    return result%M;
}

#define MAX 10000000
bitset<MAX> isPrime;
vector<ll> primes;
void gen_primes(){
  isPrime.set();
  isPrime[0]=isPrime[1]=false;
  for(ll i=2;i*i<=MAX;i++)//<=,all multiples
  {
    if(isPrime[i])
    {
      for(ll j=i;i*j<=MAX;j++)
      {
        isPrime[j*i]=false;
      }
    }
  }
  primes.pb(2);
  for(ll i=3;i<=MAX;i+=2)
  if(isPrime[i]) primes.pb(i);
}



void solve()
{
 
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
 

