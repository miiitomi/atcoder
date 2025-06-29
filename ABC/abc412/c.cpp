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
    int s, t;
    vector<int> S(N-2);
    cin >> s;
    for (int &a: S) cin >> a;
    cin >> t;
    sort(S.begin(), S.end());
    int ans = 1;
    while (true) {
        if (t <= 2*s) {
            ans++;
            cout << ans << "\n";
            return;
        }
        auto iter = lower_bound(S.begin(), S.end(), 2*s+1);
        if (iter == S.begin()) {
            break;
        }
        iter--;
        if (*iter <= s) break;
        s = *iter;
        ans++;
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
