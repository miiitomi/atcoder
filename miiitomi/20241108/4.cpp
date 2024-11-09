// https://atcoder.jp/contests/abc184/tasks/abc184_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, T;
    cin >> N >> T;
    vector<ll> A, B;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        if (i < N/2) A.push_back(a);
        else B.push_back(a);
    }
    vector<ll> v;
    for (ll s = 0; s < (1 << (int)B.size()); s++) {
        ll x = 0;
        for (int i = 0; i < (int)B.size(); i++) {
            if (s & (1 << i)) x += B[i];
        }
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ll ans = 0;
    for (ll s = 0; s < (1 << (int)A.size()); s++) {
        ll x = 0;
        for (int i = 0; i < (int)A.size(); i++) {
            if (s & (1 << i)) x += A[i];
        }
        if (x > T) continue;
        auto iter = lower_bound(v.begin(), v.end(), T+1-x);
        iter--;
        ans = max(ans, x + *iter);
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
