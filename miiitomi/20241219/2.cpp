// https://atcoder.jp/contests/abc137/tasks/abc137_c
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
    map<string, ll> mp;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        sort(S.begin(), S.end());
        mp[S]++;
    }
    ll ans = 0;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        ll n = iter->second;
        ans += n*(n-1)/2;
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
