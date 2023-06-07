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
    map<ll, ll> freq;
    map<ll, vector<ll>> mul;

    for (ll i = 0; i < n; i++)
    {
        cin >> vec[i];
        freq[vec[i]]++;
    }

    for (auto i : freq)
    {
        for (ll j = 1; j <= sqrt(i.first); j++)
        {
            if (i.first % j == 0)
            {
                if (freq[j] != 0)
                    mul[j].pb(i.first);
                if (j != i.first / j && freq[i.first / j] != 0)
                    mul[i.first / j].pb(i.first);
            }
        }
    }

    for (auto i : mul)
        pr(i.first,i.second);

    ll cnt = 0;

    for (auto i : freq)
    {
        if (freq[i.first] >= 3)
            cnt += freq[i.first] * (freq[i.first] - 1) * (freq[i.first] - 2);

        for (auto j : mul[i.first])
        {
            if (j != i.first)
            {
                ll k = j / i.first;
                if (freq[k * k * i.first] != 0)
                    cnt += freq[i.first] * freq[k * i.first] * freq[k * k * i.first];
            }
        }
    }

    cout << cnt << "\n";
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