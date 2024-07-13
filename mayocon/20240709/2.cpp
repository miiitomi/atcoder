// https://atcoder.jp/contests/abc127/tasks/abc127_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> cnt(N+2, 0);
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        cnt[l]++;
        cnt[r+1]--;
    }
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        cnt[i+1] += cnt[i];
        if (cnt[i+1] == M) ans++;
    }
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
