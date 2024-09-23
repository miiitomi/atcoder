// https://atcoder.jp/contests/abc190/tasks/abc190_c
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
    vector<ll> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }
    ll K;
    cin >> K;
    vector<ll> C(K), D(K);
    for (int i = 0; i < K; i++) {
        cin >> C[i] >> D[i];
        C[i]--; D[i]--;
    }

    ll ans = -1;
    for (ll s = 0; s < (1LL << K); s++) {
        vector<ll> cnt(N, 0);
        for (ll i = 0; i < K; i++) {
            if (s & (1 << i)) cnt[C[i]]++;
            else cnt[D[i]]++;
        }
        ll tmp = 0;
        for (ll j = 0; j < M; j++) {
            if (cnt[A[j]] >= 1 && cnt[B[j]] >= 1) tmp++;
        }
        ans = max(ans, tmp);
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
