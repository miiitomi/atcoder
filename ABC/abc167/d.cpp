#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    ll K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<vector<int>> p(60, vector<int>(N));
    for (int i = 0; i < N; i++) p[0][i] = A[i];

    for (int k = 1; k < 60; k++) {
        for (int i = 0; i < N; i++) {
            p[k][i] = p[k-1][p[k-1][i]];
        }
    }

    int u = 0;
    for (int k = 0; k < 60; k++) {
        if (K & (1LL << k)) u = p[k][u];
    }
    cout << u+1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
