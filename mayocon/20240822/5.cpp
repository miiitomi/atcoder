// https://atcoder.jp/contests/abc131/tasks/abc131_e
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
    if (K > (N-1)*(N-2)/2) {
        cout << "-1\n";
        return;
    }
    vector<vector<ll>> B(N, vector<ll>(N, false));
    for (int i = 1; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (K > 0) {
                B[i][j] = true;
                K--;
            }
        }
    }
    vector<pair<ll,ll>> V;
    for (int i = 1; i < N; i++) V.push_back({0, i});
    for (int i = 1; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (!B[i][j]) {
                V.push_back({i, j});
            }
        }
    }

    cout << V.size() << "\n";
    for (auto &p : V) {
        cout << p.first+1 << " " << p.second+1 << "\n";
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
