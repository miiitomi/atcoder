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
    cin >> N;
    vector<string> S(N);
    int M = -1;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        M = max(M, (int)S[i].size());
    }
    for (int i = 0; i < N; i++) {
        while ((int)S[i].size() < M) S[i].push_back('*');
    }

    vector<string> T(M, string(N, '*'));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            T[j][N-1-i] = S[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        while (T[i].back() == '*') T[i].pop_back();
    }

    for (string t : T) cout << t << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
