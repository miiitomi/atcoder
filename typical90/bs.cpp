#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int N, M, K;
vector<vector<int>> G;
vector<set<int>> st;
vector<int> path;
vector<bool> reached, finished;

bool dfs(int u) {
    reached[u] = true;
    for (int v : G[u]) {
        if (finished[v]) continue;
        if (reached[v] && !finished[v]) return false;
        bool res = dfs(v);
        if (!res) return false;
    }
    path.push_back(u);
    finished[u] = true;
    return true;
}

vector<int> add(vector<int> &v, int x, int i) {
    vector<int> w;
    for (int j = 0; j < (int)v.size(); j++) {
        if (i == j) w.push_back(x);
        w.push_back(v[j]);
    }
    return w;
}

void solve() {
    cin >> N >> M >> K;
    G.resize(N);
    st.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        st[b].insert(a);
    }
    reached.assign(N, false);
    finished.assign(N, false);
    for (int u = 0; u < N; u++) {
        if (st[u].empty()) {
            bool res = dfs(u);
            if (!res) {
                cout << "-1\n";
                return;
            }
        }
    }
    if ((int)path.size() != N) {
        cout << "-1\n";
        return;
    }
    reverse(path.begin(), path.end());
    vector<vector<int>> dp(1);
    for (int u : path) {
        for (auto &v : dp) {
            v.push_back(u);
        }
        int M = dp.size();
        for (int i = 0; i < M && (int)dp.size() < K; i++) {
            for (int j = dp[i].size()-2; j >= 0 && (int)dp.size() < K; j--) {
                if (st[u].contains(dp[i][j])) break;
                vector<int> w = dp[i];
                w.pop_back();
                dp.push_back(add(w, u, j));
            }
        }
    }
    if ((int)dp.size() < K) cout << "-1\n";
    else {
        for (auto &v : dp) {
            for (int x : v) cout << x+1 << " ";
            cout << "\n";
        }
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
