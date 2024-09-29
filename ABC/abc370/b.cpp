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
    vector<vector<ll>> A(N, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> A[i][j];
            A[i][j]--;
            A[j][i] = A[i][j];
        }
    }
    int x = 0;
    for (int y = 0; y < N; y++) {
        x = A[x][y];
    }
    cout << x+1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
