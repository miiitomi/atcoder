#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M, A, B;
    cin >> N >> M >> A >> B;
    deque<ll> bad;
    for (ll i = 0; i < M; i++) {
        ll l, r;
        cin >> l >> r;
        ll k = r - l + 1;
        if (k >= B) {
            cout << "No\n";
            return;
        }
        for (ll j = l; j <= r; j++) bad.push_back(j);
    }
    bad.push_back(N+1);

    vector<vector<ll>> to(51, vector<ll>(1LL << B, 0LL));
    for (ll s = 0; s < (1LL << B); s++) {
        ll t = s;
        for (ll i = 0; i < B; i++) {
            if (!(s & (1 << i))) continue;
            for (ll j = i+A; j <= B; j++) {
                t |= (1LL << j);
            }
        }
        to[0][s] = (t >> 1);
    }
    for (ll k = 1; k <= 50; k++) {
        for (ll s = 0; s < (1LL << B); s++) {
            to[k][s] = to[k-1][to[k-1][s]];
        }
    }

    ll tmp = 1;
    ll s = (1 << (B-1));
    while (tmp < N) {
        if (tmp+1 < bad.front()) {
            ll k = 0;
            while (tmp + (1LL << (k+1)) < bad.front()) k++;
            s = to[k][s];
            tmp += (1LL << k);
        } else {
            tmp++;
            s = to[0][s];
            ll r = tmp, l = tmp - B + 1;
            while (bad.front() < l) bad.pop_front();
            for (ll x : bad) {
                if (x > r) break;
                if (s & (1LL << (x - l))) s -= (1LL << (x-l));
            }
        }
    }

    if (s & (1LL << (B-1))) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    ll T = 1;
    // cin >> T;
    while (T--) solve();
}
