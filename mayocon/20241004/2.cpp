// https://atcoder.jp/contests/abc210/tasks/abc210_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    map<ll, ll> mp;
    queue<ll> Q;
    for (int i = 0; i < K; i++) {
        ll x;
        cin >> x;
        mp[x]++;
        Q.push(x);
    }
    ll ans = mp.size();
    ll tmp = ans;
    for (int i = 0; i < N-K; i++) {
        ll x = Q.front();
        Q.pop();
        mp[x]--;
        if (mp[x] == 0) tmp--;
        cin >> x;
        mp[x]++;
        if (mp[x] == 1) tmp++;
        Q.push(x);
        ans = max(ans, tmp);
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
