// https://atcoder.jp/contests/abc362/tasks/abc362_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<vector<ll>> G;
vector<ll> cnt;

void count_cnt(int u, int p) {
    cnt[u] = 1;
    for (int v : G[u]) {
        if (p == v) continue;
        count_cnt(v, u);
        cnt[u] += cnt[v];
    }
}

int find_central(int u, int p) {
    ll max_num = -1;
    int mv = -1;
    for (int v : G[u]) {
        if (v == p) continue;
        if (max_num < cnt[v]) {
            max_num = cnt[v];
            mv = v;
        }
    }
    if (max_num <= N/2) return u;
    else return find_central(mv, u);
}

void make_vector(int u, int p, vector<int> &V) {
    for (int v : G[u]) {
        if (p == v) continue;
        make_vector(v, u, V);
    }
    V.push_back(u);
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cnt.resize(N, 0);
    count_cnt(0, -1);
    int r = find_central(0, -1);

    vector<int> V;
    for (int u : G[r]) {
        vector<int> w;
        make_vector(u, r, w);
        for (int v : w) V.push_back(v);
    }

    if (N%2 == 0) V.push_back(r);

    for (int i = 0; i < N/2; i++) {
        cout << V[i]+1 << " " << V[i+N/2]+1 << "\n";
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
