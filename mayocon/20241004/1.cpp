// https://atcoder.jp/contests/abc231/tasks/abc231_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    map<string, ll> mp;
    while (N--) {
        string s;
        cin >> s;
        mp[s]++;
    }
    string ans;
    ll v = -INF;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        if (v < iter->second) {
            v = iter->second;
            ans = iter->first;
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
