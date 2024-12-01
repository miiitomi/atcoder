// https://atcoder.jp/contests/abc287/tasks/abc287_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll lcp(string s, string t) {
    ll ans = 0;
    for (int i = 0; i < min((int)s.size(),(int)t.size()); i++) {
        if (s[i] != t[i]) return ans;
        ans++;
    }
    return ans;
}

void solve() {
    ll N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    vector<string> T = S;
    sort(T.begin(), T.end());
    for (string &s : S) {
        auto iter = lower_bound(T.begin(), T.end(), s);
        iter++;
        ll ans = -1;
        if (iter != T.end()) ans = max(ans, lcp(s, *iter));
        iter--;
        if (iter != T.begin()) {
            iter--;
            ans = max(ans, lcp(s, *iter));
        }
        cout << ans << "\n";
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
