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
    vector<pair<ll, ll>> V(N);
    multiset<ll> st;
    for (int i = 0; i < N; i++) {
        cin >> V[i].first >> V[i].second;
        st.insert(V[i].second);
    }
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    ll ans = 0;
    for (ll l = 1; l <= M; l++) {
        while (!V.empty() && V.back().first < l) {
            st.erase(st.lower_bound(V.back().second));
            V.pop_back();
        }
        ll r = M;
        if (!st.empty()) r = *st.begin() - 1;
        if (r >= l) ans += r - l + 1;
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
