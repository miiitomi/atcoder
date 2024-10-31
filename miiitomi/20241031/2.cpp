// https://atcoder.jp/contests/abc081/tasks/arc086_a
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
    multiset<ll> st;
    vector<ll> cnt(N, 0);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        a--;
        cnt[a]++;
    }
    for (ll a: cnt) if (a > 0) st.insert(a);

    ll ans = 0;
    while ((int)st.size() > K) {
        auto iter = st.begin();
        ll mi = *iter;
        st.erase(iter);
        auto iter2 = st.end();
        iter2--;
        ll ma = *iter2;
        st.erase(iter2);
        ans += mi;
        st.insert(mi + ma);
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
