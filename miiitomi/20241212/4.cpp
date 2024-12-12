// https://atcoder.jp/contests/abc067/tasks/arc078_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int N;
vector<vector<int>> G;

vector<int> dist(int u) {
    vector<int> d(N, -1);
    d[u] = 0;
    queue<int> Q;
    Q.push(u);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int w : G[v]) {
            if (d[w] != -1) continue;
            d[w] = d[v] + 1;
            Q.push(w);
        }
    }
    return d;
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> d0 = dist(0);
    vector<int> path{N-1};
    while (path.back() != 0) {
        int u = path.back();
        for (int v : G[u]) {
            if (d0[v] == d0[u]-1) {
                path.push_back(v);
                break;
            }
        }
    }
    reverse(path.begin(), path.end());
    int s = path[(path.size()-1)/2], t = path[(path.size()-1)/2 + 1];
    vector<int> ds = dist(s), dt = dist(t);
    int S = 0, T = 0;
    for (int i = 0; i < N; i++) {
        if (ds[i] < dt[i]) S++;
        else T++;
    }

    if (T >= S) cout << "Snuke\n";
    else cout << "Fennec\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
