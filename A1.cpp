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

#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define pr(...) \
    {           \
    }
#define debarr(a, n) \
    {                \
    }
#define debmat(mat, row, col) \
    {                         \
    }
#endif

void solve()
{
    ll n;
    cin >> n;
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    sort(all(vec));

    ll i = 0, j = n - 1;

    pr(vec);

    j--;
    while (vec[n] - vec[j] > vec[n] - vec[j - 1])
    {
        j--;
    }

    i++;
    while (vec[i] - vec[0] > vec[i + 1] - vec[0])
    {
        i++;
    }

    ll ans = 0;

    ans += (vec[n] - vec[j]) / 2 + (vec[i] - vec[0]) / 2;
    if(i<j)
    {
        ans+= (vec[i + 1] - vec[j - 1]) / 2;
    }

    cout << ans << "\n";
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
