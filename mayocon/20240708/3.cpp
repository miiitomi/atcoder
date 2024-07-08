// https://atcoder.jp/contests/abc254/tasks/abc254_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    vector<vector<int>> v(K);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        v[i%K].push_back(a[i]);
    }
    sort(a.begin(), a.end());
    vector<int> b(N);
    for (int k = 0; k < K; k++) {
        sort(v[k].begin(), v[k].end());
        for (int s = 0; s < (int)v[k].size(); s++) {
            b[s*K+k] = v[k][s];
        }
    }
    if (a == b) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
