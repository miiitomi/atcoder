// https://atcoder.jp/contests/abc269/tasks/abc269_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<ll> num_decomposition(ll N) {
    vector<ll> v;
    ll x = 1;
    while (N > 0) {
        ll m = min(N, x);
        v.push_back(m);
        N -= m;
        x *= 2;
    }
    return v;
}

vector<pair<ll,ll>> vector_decomposition(vector<pair<ll,ll>> &F) {
    vector<pair<ll,ll>> G;
    for (auto &p : F) {
        vector<ll> v = num_decomposition(p.second);
        for (ll x : v) G.push_back({p.first, x});
    }
    return G;
}

vector<pair<ll,ll>> num_vector_to_pair(vector<ll> &C) {
    vector<ll> v = C;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<ll> cnt(v.size(), 0);
    for (ll c : C) {
        cnt[distance(v.begin(), lower_bound(v.begin(), v.end(), c))]++;
    }
    vector<pair<ll,ll>> V;
    for (int i = 0; i < (int)v.size(); i++) V.push_back({v[i], cnt[i]});
    return V;
}

void solve() {
    ll N, M;
    cin >> N >> M;
    ll sum_a = 0;
    vector<ll> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        sum_a += A[i];
        C[i] = B[i] - A[i];
    }
    vector<pair<ll,ll>> F = num_vector_to_pair(C);
    F = vector_decomposition(F);
    vector<ll> dp(M+1, INF);
    dp[sum_a] = 0;
    for (auto &e : F) {
        vector<ll> ndp = dp;
        auto [c, n] = e;
        for (ll i = 0; i <= M; i++) {
            if (dp[i] != INF && 0 <= i + n*c && i + n*c <= M) {
                ndp[i+n*c] = min(ndp[i+n*c], dp[i] + n);
            }
        }
        swap(dp, ndp);
    }
    for (ll x : dp) {
        if (x == INF) cout << -1 << "\n";
        else cout << x << "\n";
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
