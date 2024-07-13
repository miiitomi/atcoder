// https://atcoder.jp/contests/abc127/tasks/abc127_d
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
    vector<ll> A(N), v;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        v.push_back(A[i]);
    }
    vector<ll> B(M), C(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i] >> C[i];
        v.push_back(C[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (ll &a : A) a = distance(v.begin(), lower_bound(v.begin(), v.end(), a));
    for (ll &c : C) c = distance(v.begin(), lower_bound(v.begin(), v.end(), c));

    vector<ll> cnt(v.size(), 0);
    for (ll a : A) cnt[a]++;
    for (int i = 0; i < M; i++) cnt[C[i]] += B[i];

    ll remain = N;
    ll ans = 0;
    for (int i = v.size()-1; i >= 0; i--) {
        ll x = min(remain, cnt[i]);
        ans += v[i]*x;
        remain -= x;
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
