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
    vector<int> A(M), B(M);
    dsu U(N);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        U.merge(A[i], B[i]);
    }
    vector<int> cnt(N, 0);
    for (int i = 0; i < M; i++) {
        int r = U.leader(A[i]);
        cnt[r]++;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (i != U.leader(i)) continue;
        int s = U.size(i);
        ans += cnt[i] - (s-1);
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
