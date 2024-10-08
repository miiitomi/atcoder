// https://atcoder.jp/contests/abc364/tasks/abc364_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    a.push_back(-INF);
    a.push_back(INF);
    sort(a.begin(), a.end());
    while (Q--) {
        ll b, k;
        cin >> b >> k;
        ll left = -1, right = (ll)2e+9;
        while (right - left > 1) {
            ll m = (left + right) / 2;
            auto iter = lower_bound(a.begin(), a.end(), b - m);
            auto iter2 = lower_bound(a.begin(), a.end(), b + m + 1);
            ll cnt = distance(iter, iter2);
            if (cnt >= k) right = m;
            else left = m;
        }
        cout << right << "\n";
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
