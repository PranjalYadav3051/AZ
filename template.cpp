#include <bits/stdc++.h>
using namespace std;
#define ll             long long
#define M 1000000007



//POWER
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
//MOD
ll mod(ll a, ll m) {
return (a%m+m)%m;
}
 

// 2D VECTOR
vector<vector<ll>> vec( n , vector<ll> (m, 0)); 

//New way 
using ii = pair<long,long>;

//Modular Multiplicative Inverse : Modular Arithmetic for Division

ll mod(ll a, ll m) {
return (a%m+m)%m;
}

ll power(ll x,ll n)
{   ll result=1;
    while(n>0)
        {   if(n % 2 ==1)
            result=mod(result * x,M);
            x=mod(x*x,M);
            n=n/2;
        }
    return mod(result,M);
}

ll binexp(ll a, ll x,ll y)
{
ll d = power(a,x-2);
return mod(d,y);
}

// Recursive Implementation of Euclid's Algorithm
ll  gcd(ll m, ll n)
{
    if(n == 0) return m;

    return gcd(n, m % n);
}


//time taken
{
    clock_t start, end;
start = clock();
//Function calls
end = clock();
double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
cout << fixed << setprecision(10) << time_taken << " sec" << endl;
}

// sort by sec
template < class T1,class T2>
bool secondsort(pair<T1,T2> a, pair<T1,T2> b)
{
    return a.second < b.second;
}



//PBDS
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int> /*comparator*/, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key