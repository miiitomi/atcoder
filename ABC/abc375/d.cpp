#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string S;
    cin >> S;
    vector<vector<int>> cnt(26);
    ll N = S.size();
    for (int i = 0; i < N; i++) {
        cnt[(int)(S[i]-'A')].push_back(i);
    }
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        int c = (int)(S[i]-'A');
        for (int d = 0; d < 26; d++) {
            ll r = distance(lower_bound(cnt[d].begin(), cnt[d].end(), i+1), cnt[d].end());
            ll l = cnt[d].size() - r;
            if (c == d) l--;
            ans += l*r;
        }
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
