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
    for (string &s : S) cin >> s;
    scc_graph sg(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][1] == S[j][0]) {
                sg.add_edge(i, j);
            }
        }
    }
    auto scc = sg.scc();
    int M = scc.size();
    vector<int> group(N);
    for (int i = 0; i < M; i++) {
        for (int j : scc[i]) {
            group[j] = i;
        }
    }
    vector<bitset<1000>> A(M, 0);
    for (int i = M-1; i >= 0; i--) {
        for (int u : scc[i]) {
            for (int v = 0; v < N; v++) {
                if (S[u][1] == S[v][0]) {
                    A[i] |= A[group[v]];
                    A[i][group[v]] = 1;
                }
            }
        }
    }
    mf_graph<int> mg(2*M + 2);
    int s = 2*M, t = 2*M + 1;
    for (int i = 0; i < M; i++) {
        mg.add_edge(s, 2*i, 1);
        mg.add_edge(2*i + 1, t, 1);
        for (int j = i+1; j < M; j++) {
            if (A[i][j]) {
                mg.add_edge(2*i, 2*j+1, 1);
            }
        }
    }
    int ans = M - mg.flow(s, t);
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
