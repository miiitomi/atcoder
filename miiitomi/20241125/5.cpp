// https://atcoder.jp/contests/abc149/tasks/abc149_e
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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    CumulativeSum<ll> S(A);

    ll left = 0, right = 2e+5 + 1;
    while (right - left > 1) {
        ll m = (left + right) / 2;
        ll cnt = 0;
        for (int i = 0; i < N; i++) {
            auto iter = lower_bound(A.begin(), A.end(), m - A[i]);
            cnt += distance(iter, A.end());
            if (cnt >= M) break;
        }
        if (cnt >= M) left = m;
        else right = m;
    }

    ll ans = 0;
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        auto iter = lower_bound(A.begin(), A.end(), left - A[i] + 1);
        ll m = distance(iter, A.end());
        ans += m*A[i] + S.query(N-m, N);
        cnt += m;
    }
    ans += (M - cnt) * left;
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
