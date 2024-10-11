// https://atcoder.jp/contests/abc134/tasks/abc134_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, D;
    cin >> N >> D;
    int ans = 1e+9;
    for (int st = 1; st < (1 << N); st++) {
        vector<bool> ok(N, false);
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (!(st & (1 << i))) continue;
            cnt++;
            for (int j = max(0, i-D); j <= min(N-1, i+D); j++) ok[j] = true;
        }
        bool tmp = true;
        for (int i = 0; i < N; i++) if (!ok[i]) tmp = false;
        if (tmp) ans = min(ans, cnt);
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
