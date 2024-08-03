// https://atcoder.jp/contests/abc215/tasks/abc215_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    set<ll> S;
    for (ll x = 1; x <= M; x++) S.insert(x);
    vector<ll> v;
    while (N--) {
        ll a;
        cin >> a;
        for (ll x = 1; x*x <= a; x++) {
            if (a%x == 0) {
                v.push_back(x);
                v.push_back(a/x);
            }
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<bool> is_ok(M+1, true);
    for (ll x : v) {
        if (x == 1) continue;
        for (ll y = x; y <= M; y += x) {
            is_ok[y] = false;
        }
    }
    vector<ll> ans;
    for (ll x = 1; x <= M; x++) {
        if (is_ok[x]) {
            ans.push_back(x);
        }
    }
    cout << ans.size() << "\n";
    for (ll y : ans) cout << y << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
