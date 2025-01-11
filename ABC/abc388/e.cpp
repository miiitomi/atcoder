#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll left = 0, right = N/2 + 1;
    while (right - left > 1) {
        ll m = (left + right) / 2;
        bool ok = true;
        for (int i = 0; i < m; i++) {
            ll a = A[i], b = A[N-m+i];
            if (b < 2*a) {
                ok = false;
                break;
            }
        }
        if (ok) left = m;
        else right = m;
    }
    cout << left << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
