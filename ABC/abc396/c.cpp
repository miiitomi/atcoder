#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<ll> B(N), W(M);
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < M; i++) cin >> W[i];
    sort(B.begin(), B.end(), [](ll l, ll r) {return l > r;});
    sort(W.begin(), W.end(), [](ll l, ll r) {return l > r;});
    segtree<ll, [](ll l, ll r) {return max(l, r);}, []() {return -INF;}> st(max(N, M)+1);
    st.set(0, 0);

    ll sum = 0, ans = 0;
    for (int i = 0; i < M; i++) {
        sum += W[i];
        st.set(i+1, sum);
    }
    sum = 0;
    for (int i = 0; i < N; i++) {
        sum += B[i];
        ans = max(ans, sum + st.prod(0, i+2));
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
