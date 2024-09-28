#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

double dist(pair<ll,ll> &p, pair<ll,ll> &q) {
    return sqrt((p.first-q.first)*(p.first-q.first)+(p.second-q.second)*(p.second-q.second)+0.0);
}

void solve() {
    ll N;
    cin >> N;
    vector<pair<ll,ll>> P(N), Q(N);
    for (int i = 0; i < N; i++) cin >> P[i].first >> P[i].second;
    for (int i = 0; i < N; i++) cin >> Q[i].first >> Q[i].second;
    mcf_graph<int, double> mcfg(2*N + 2);
    int s = 2*N, t = 2*N + 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mcfg.add_edge(i, N+j, 1, dist(P[i], Q[j]));
        }
    }
    for (int i = 0; i < N; i++) mcfg.add_edge(s, i, 1, 0);
    for (int i = 0; i < N; i++) mcfg.add_edge(N+i, t, 1, 0);
    mcfg.flow(s, t);
    auto edges = mcfg.edges();
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int k = i*N + j;
            if (edges[k].flow) A[i] = j;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << A[i]+1;
        if (i == N-1) cout << "\n";
        else cout << " ";
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
