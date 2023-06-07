#include <bits/stdc++.h>

using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define M 1e9 + 7

#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ps(x, y) fixed << setprecision(y) << x
#define w(x)  \
    ll x;     \
    cin >> x; \
    while (x--)
#define google cout << "Case #" << test_num << ": "
#define hi(x) cout << "hi" << x << endl;
#define ACC(v) accumulate(v.begin(), v.end(), 0ll)

// #ifndef ONLINE_JUDGE
// #include "debug.hpp"
// #else
// #define pr(...){}
// #define debarr(a,n){}
// #define debmat(mat,row,col){}
// #endif
// knapsack
// https://www.codechef.com/problems/KNPSK

// 1. -> time complexity: O(2^n)
// 2. -> time complexity: O(2^n)


// 3. -> time complexity: O(n*b*k)
//-----------------------------------

// describe what the code below do
// 1. take the current element
// 2. don't take the current element
// 3. return the maximum of both

// DP SOLUTION
// REMOVE THE BULKY data structure that we maintianed to find ans , instead variables can be used
// becaused the bulku structure cur can't be cached easily
// so we can use variables instead of cur , startes of the problem

// mostly th eparameters that are required to check that ans is valid or not becomes part of state


int n;
int b, k;
int p[100100];
int h[100100];

// vector<pair<ll, ll>> cur;
ll ans = 0;

ll dp[101][1001][101];

//void rec(int level, ll totalhap , ll totalcost, ll cursize)
ll rec(int level , ll totalcost, ll cursize)
{
    if (level == n)
    {
        return 0;
    }

    if(dp[level][totalcost][cursize] != -1)
    {
        return dp[level][totalcost][cursize];
    }

    ll ans  = rec(level + 1,totalcost,cursize);

    if(totalcost + p[level] <= b && cursize + 1 <= k) // pruning the search space
    {
        // only the max of ans will be returned
        ans = max(ans, h[level] + rec(level + 1 ,totalcost + p[level],cursize + 1));
    }

    return dp[level][totalcost][cursize] = ans;
    //return ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> h[i];
    }

    memset(dp,-1,sizeof(dp));
    cin >> b >> k;
    rec(0, 0, 0 );
    cout << ans << endl;
}

int32_t main()
{
    fast;
    //   #ifndef ONLINE_JUDGE
    //   freopen("Error.txt", "w", stderr);
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);
    //   #endif

    w(t)
        solve();
}


// ll rec(int level , ll totalcost, ll cursize)
// {
//     if (level == n)
//     {
//         // ll totalcost = 0;
//         // ll totalhap = 0;

//         // for (auto x : cur)
//         // {
//         //     totalcost += x.first;
//         //     totalhap += x.second;
//         // }

//         // //if (totalcost <= b && cur.size() <= k)
//         // if (totalcost <= b && cursize <= k)// pruning the search space
//         // {
//         //     ans = max(ans, totalhap);
//         // }

//         return 0;
//     }

//     // // don't take
//     // {
//     //     rec(level + 1,totalhap,totalcost,cursize);
//     // }

//     // // take
//     // {
//     //     //cur.pb({p[level], h[level]});
//     //     rec(level + 1,totalhap + h[level],totalcost + p[level],cursize + 1);
//     //     //cur.pop_back();
//     // }


//     ll ans  = rec(level + 1,totalcost,cursize);

//     if(totalcost + p[level] <= b && cursize + 1 <= k) // pruning the search space
//     {
//         // only the max of ans will be returned
//         ans = max(ans, h[level] + rec(level + 1 ,totalcost + p[level],cursize + 1));
//     }
    
//     return ans;
// }