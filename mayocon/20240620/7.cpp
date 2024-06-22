// https://atcoder.jp/contests/abc156/tasks/abc156_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void f(ll k, ll n, ll x, ll m, vector<ll> d) {
    ll sum = 0;
    for (int i = 0; i < k; i++) {
        d[i] %= m;
        sum += d[i];
    }

    ll ans = n-1;

    ll a_0 = x;
    ll a_n1 = x + ((n-1) / k) * sum;
    ll tmp = ((n-1)/k) * k, idx = 0;
    while (tmp < n-1) {
        a_n1 += d[idx];
        tmp++;
        idx++;
    }

    ans -= (a_n1)/m - (a_0)/m;

    for (int i = 0; i < k; i++) {
        if (d[i] != 0) continue;
        ll x = n-1 - i;
        x = (x + k-1) / k;
        ans -= x;
    }

    cout << ans << endl;
}

void solve() {
    ll k, q;
    cin >> k >> q;
    vector<ll> d(k);
    for (int i = 0; i < k; i++) cin >> d[i];
    while (q--) {
        ll n, x, m;
        cin >> n >> x >> m;
        f(k, n, x, m, d);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
