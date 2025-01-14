// https://atcoder.jp/contests/abc206/tasks/abc206_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int N;
vector<pair<int,int>> A;
vector<vector<int>> G;

void solve() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
        A[i].first--;
        A[i].second--;
    }
    G.assign(100, vector<int>(100, 0));
    for (int k = 1; k <= 99; k++) {
        for (int l = 0; l+k <= 99; l++) {
            int r = l+k;
            vector<bool> remained(110, true);
            for (int i = 0; i < N; i++) {
                auto [a, b] = A[i];
                if (!(l <= a && b <= r)) continue;
                int g = G[l][a]^G[b][r];
                remained[g] = false;
            }
            for (int g = 0; g < 110; g++) {
                if (remained[g]) {
                    G[l][r] = g;
                    break;
                }
            }
        }
    }

    if (G[0][99]) cout << "Alice\n";
    else cout << "Bob\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
