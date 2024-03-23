#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, K;
    cin >> N >> K;
    ll ans = ((1+K) * K) / 2;
    set<ll> S;
    while (N--) {
        ll x;
        cin >> x;
        if (!S.count(x) && x <= K) {
            ans -= x;
            S.insert(x);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
