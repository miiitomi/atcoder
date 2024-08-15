// https://atcoder.jp/contests/abc353/tasks/abc353_a
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
    vector<ll> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    for (int i = 1; i < N; i++) {
        if (H[0] < H[i]) {
            cout << i+1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
