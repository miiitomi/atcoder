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
    vector<ll> V, ans(N, 0);
    for (int i = N-2; i >= 0; i--) {
        while (!V.empty() && V.back() < H[i+1]) V.pop_back();
        V.push_back(H[i+1]);
        ans[i] = V.size();
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << ((i < N-1) ? " " : "\n");
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
