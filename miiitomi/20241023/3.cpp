// https://atcoder.jp/contests/abc152/tasks/abc152_d
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
    vector<vector<ll>> cnt(10, vector<ll>(10, 0));
    for (ll x = 1; x <= N; x++) {
        string s = to_string(x);
        int a = s.front()-'0', b = s.back()-'0';
        cnt[a][b]++;
    }
    ll ans = 0;
    for (int a = 1; a <= 9; a++) {
        for (int b = 1; b <= 9; b++) {
            ans += cnt[a][b]*cnt[b][a];
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
