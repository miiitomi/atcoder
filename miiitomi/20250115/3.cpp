// https://atcoder.jp/contests/abc059/tasks/arc072_a
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
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll ans = INF;
    for (int k = 0; k < 2; k++) {
        fenwick_tree<ll> ft(N);
        for (int i = 0; i < N; i++) ft.add(i, A[i]);
        bool pos = (k == 0);
        ll cnt = 0;
        for (int i = 0; i < N; i++) {
            ll a = 0;
            ll tmp = ft.sum(0, i+1);
            if (pos) {
                if (tmp <= 0) a = -tmp + 1;
            } else {
                if (tmp >= 0) a = -tmp - 1;
            }
            cnt += abs(a);
            ft.add(i, a);
            pos ^= true;
        }
        ans = min(ans, cnt);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
