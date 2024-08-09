// https://atcoder.jp/contests/abc228/tasks/abc228_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N = (1 << 20);
    vector<ll> A(N, -1);
    set<ll> S;
    for (int i = 0; i < N; i++) S.insert(i);
    ll Q;
    cin >> Q;
    while (Q--) {
        ll t, x;
        cin >> t >> x;
        if (t == 1) {
            ll h = x % N;
            auto iter = S.lower_bound(h);
            if (iter == S.end()) iter = S.begin();
            ll i = *iter;
            S.erase(iter);
            A[i] = x;
        } else {
            cout << A[x%N] << "\n";
        }
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
