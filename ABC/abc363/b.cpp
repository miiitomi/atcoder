#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, T, P;
    cin >> N >> T >> P;
    vector<ll> L(N);
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> L[i];
        if (L[i] >= T) cnt++;
    }

    ll ans = 0;
    while (cnt < P) {
        cnt = 0;
        ans++;
        for (int i = 0; i < N; i++) {
            L[i]++;
            if (L[i] >= T) cnt++;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
