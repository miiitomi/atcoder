// https://atcoder.jp/contests/typical90/tasks/typical90_c
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
    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int s = 0;
    vector<int> d;
    for (int k = 0; k < 2; k++) {
        d = vector<int>(N, 1e+9);
        d[s] = 0;
        queue<int> Q;
        Q.push(s);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (int v : G[u]) {
                if (d[v] > d[u]+1) {
                    d[v] = d[u]+1;
                    Q.push(v);
                }
            }
        }
        s = distance(d.begin(), max_element(d.begin(), d.end()));
    }
    cout << *max_element(d.begin(), d.end())+1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
