// https://atcoder.jp/contests/abc130/tasks/abc130_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> struct CumulativeSum {
    int N;
    vector<T> data;

    CumulativeSum(vector<T> &A) {
        N = A.size();
        data.assign(N+1, 0);
        for (int i = 0; i < N; i++) data[i+1] = data[i] + A[i];
    }

    T query(int l, int r) {
        // Return Sum of [l, r)
        return data[r]-data[l];
    }
};

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    CumulativeSum<ll> S(a);

    ll ans = 0;
    for (int l = 0; l < N; l++) {
        if (S.query(l, N) < K) break;
        ll left = l, right = N;
        while (right - left > 1) {
            ll m = (left + right) / 2;
            if (S.query(l, m) >= K) right = m;
            else left = m;
        }
        ans += N - right + 1;
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
