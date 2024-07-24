// https://atcoder.jp/contests/abc268/tasks/abc268_e
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
    vector<ll> p(N), q(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        q[p[i]] = i;
    }

    vector<ll> a(2*N + 1, 0);
    for (int i = 0; i < N; i++) {
        ll m = ((N+1)/2 + i) % N;
        ll s;
        if (q[i] <= m) s = m - q[i];
        else s = (m+N) - q[i];

        a[s] += 1;
        if (s + N/2 <= 2*N) a[s + (N/2)] += -2;
        if (s + (N/2) + (N/2) <= 2*N) a[s + (N/2) + (N/2)] += 1;
        if (s + (N/2) + (N+1)/2 <= 2*N) a[s + (N/2) + (N+1)/2] += 1;
        if (s + N/2 + N <= 2*N) a[s + N/2 + N] += -2;
        if (s + N/2 + N + N/2 <= 2*N) a[s + N/2 + N + N/2] += 1;
        if (s + N/2 + N + (N+1)/2 <= 2*N) a[s + N/2 + N + (N+1)/2] += 1;

    }

    for (int i = 0; i < 2*N; i++) a[i+1] += a[i];

    ll ans = -1;
    ll x = 0;
    for (int i = 0; i < 2*N; i++) {
        ans = max(ans, x);
        x += a[i];
    }
    ans = max(ans, x);

    cout << (N/2)*N - ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
