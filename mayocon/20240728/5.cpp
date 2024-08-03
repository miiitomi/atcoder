// https://atcoder.jp/contests/abc296/tasks/abc296_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool dfs(ll u, vector<ll> &A, vector<bool> &done, vector<ll> &path, set<ll> &S) {
    if (done[u]) {
        if (S.count(u)) {
            reverse(path.begin(), path.end());
            while (path.back() != u) path.pop_back();
            return true;
        }
        return false;
    }
    done[u] = true;
    path.push_back(u);
    S.insert(u);
    return dfs(A[u], A, done, path, S);
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<bool> done(N, false);
    vector<bool> is_ok(N, false);
    for (ll u = 0; u < N; u++) {
        if (done[u]) continue;
        vector<ll> path;
        set<ll> S;
        if (dfs(u, A, done, path, S)) {
            for (ll v: path) is_ok[v] = true;
        }
    }

    ll ans = 0;
    for (ll u = 0; u < N; u++) ans += is_ok[u];
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
