// https://atcoder.jp/contests/abc111/tasks/arc103_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<pair<ll,ll>> f(vector<ll> &V) {
    ll N = V.size();
    vector<ll> cnt(1e+5 + 1, 0);
    for (ll v : V) cnt[v]++;
    vector<pair<ll,ll>> ans;
    for (int i = 0; i <= 1e+5; i++) {
        ans.push_back({N-cnt[i], i});
    }
    sort(ans.begin(), ans.end());
    while (ans.size() > 2) ans.pop_back();
    return ans;
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> v, w;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        x--;
        if (i % 2 == 0) v.push_back(x);
        else w.push_back(x);
    }
    auto x = f(v), y = f(w);
    ll ans = INF;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (x[i].second == y[j].second) continue;
            ans = min(ans, x[i].first + y[j].first);
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
