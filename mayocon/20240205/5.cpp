// https://atcoder.jp/contests/abc222/tasks/abc222_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

int N, M, K;
vector<vector<pair<int,int>>> G;
vector<int> cnt;
int mid = (int)1e+5;

bool dfs(int u, int p, int t, vector<int> &path) {
    if (u == t) {
        for (int i : path) cnt[i]++;
        return true;
    }
    for (auto e : G[u]) {
        if (e.first == p) continue;
        path.push_back(e.second);
        bool res = dfs(e.first, u, t, path);
        if (res) return true;
        path.pop_back();
    }
    return false;
}

void count_path(int s, int t) {
    vector<int> path;
    dfs(s, -1, t, path);
}

void solve() {
    cin >> N >> M >> K;
    G.resize(N);
    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
        A[i]--;
    }
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(make_pair(v, i));
        G[v].push_back(make_pair(u, i));
    }
    cnt.assign(N-1, 0);
    for (int i = 0; i < M-1; i++) count_path(A[i], A[i+1]);

    vector<ll> dp(2*mid+1, 0);
    dp[mid] = 1;
    for (int i = 0; i < N-1; i++) {
        vector<ll> ndp(2*mid + 1, 0);
        for (int j = 0; j <= 2*mid; j++) {
            if (dp[j] == 0) continue;
            ndp[j + cnt[i]] += dp[j];
            if (ndp[j + cnt[i]] > MOD) ndp[j + cnt[i]] -= MOD;
            ndp[j - cnt[i]] += dp[j];
            if (ndp[j - cnt[i]] > MOD) ndp[j - cnt[i]] -= MOD;
        }
        swap(dp, ndp);
    }

    cout << dp[mid + K] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
