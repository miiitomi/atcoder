// https://atcoder.jp/contests/abc249/tasks/abc249_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll M = 2e+5;
    ll N;
    cin >> N;
    vector<ll> cnt(M+1, 0);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        cnt[a]++;
    }
    ll ans = 0;
    for (ll a = 1; a <= M; a++) {
        for (ll b = 1; a*b <= M; b++) {
            ans += cnt[a]*cnt[b]*cnt[a*b];
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
