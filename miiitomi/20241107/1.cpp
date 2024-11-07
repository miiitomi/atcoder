// https://atcoder.jp/contests/abc227/tasks/abc227_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    set<ll> st;
    for (ll a = 1; a <= 1000; a++) {
        for (ll b = 1; b <= 1000; b++) {
            st.insert(4*a*b+3*a+3*b);
        }
    }
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        if (!st.contains(a)) cnt++;
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
