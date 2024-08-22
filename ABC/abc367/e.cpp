#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<vector<int>> p(60, vector<int>(N));
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> p[0][i];
        p[0][i]--;
    }
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int k = 1; k < 60; k++) {
        for (int u = 0; u < N; u++) {
            p[k][u] = p[k-1][p[k-1][u]];
        }
    }

    vector<int> v(N);
    iota(v.begin(), v.end(), 0);
    for (int k = 0; k < 60; k++) {
        if (!(K & (1LL << k))) continue;
        vector<int> nv(N);
        for (int i = 0; i < N; i++) nv[i] = p[k][v[i]];
        swap(v, nv);
    }
    for (int i = 0; i < N; i++) cout << A[v[i]] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
