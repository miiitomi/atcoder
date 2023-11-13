#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll MOD = 1e+9 + 7;

ll F(ll x) {
    ll y = 1, cnt = 0;
    while (2*y <= x) {
        y *= 2;
        cnt++;
    }
    return cnt;
}

ll G(ll x) {
    ll y = 1, f = F(x), cnt = 0;
    while (y * f <= x) {
        y *= f;
        cnt++;
    }
    return cnt;
}

int main() {
    map<ll, ll> mp;
    ll x = 4;

    while (x <= 1e+18) {
        ll f = F(x), g = G(x);
        mp[x] = g;
        ll l = (1LL << (f + 1));
        ll r = 1;
        for (int k = 0; k < (g+1); k++) r *= f;
        x = min(l, r);
    }
    mp[1 + (ll)1e+18] = 11;

    vector<ll> s, t;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        s.push_back(iter->first);
        t.push_back(iter->second);
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        ll l, r;
        cin >> l >> r;

        int i = 0;
        while (s[i] <= l) i++;
        i--;

        ll ans = 0;

        while (l <= r) {
            ll y = t[i];
            i++;
            ans = (ans + (min(s[i] - 1, r) - l + 1) % MOD * y % MOD) % MOD;
            l = s[i];
        }

        cout << ans << endl;
    }
}
