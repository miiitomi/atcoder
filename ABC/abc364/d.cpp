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
    sort(a.begin(), a.end());

    while (Q--) {
        ll b, k;
        cin >> b >> k;
        ll left = -1, right = 2e+9;
        while (right - left > 1) {
            ll m = (left + right) / 2;
            auto iter1 = lower_bound(a.begin(), a.end(), b - m);
            auto iter2 = lower_bound(a.begin(), a.end(), b + m + 1);
            if (distance(iter1, iter2) >= k) right = m;
            else left = m;
        }
        cout << right << endl;
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
