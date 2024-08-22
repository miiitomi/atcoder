// https://atcoder.jp/contests/abc345/tasks/abc345_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string s;
    cin >> s;
    vector<ll> cnt(26, 0);
    ll ans = 0;
    bool b = false;
    for (int i = 0; i < (int)s.size(); i++) {
        ans += i - cnt[s[i]-'a'];
        if (cnt[s[i]-'a']) b = true;
        cnt[s[i]-'a']++;
    }
    cout << ans + b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
