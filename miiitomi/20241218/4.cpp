// https://atcoder.jp/contests/abc046/tasks/arc062_b
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
    string S;
    cin >> S;
    int N = S.size();
    vector<ll> P(N, 0);
    for (int i = 0; i < N; i++) P[i] = (S[i] == 'p');
    CumulativeSum<ll> CS(P);
    int left = 0, right = N;
    while (right - left > 1) {
        ll m = (left + right) / 2;
        ll cnt = CS.query(0, m) + N-m;
        if (cnt <= N/2) right = m;
        else left = m;
    }
    ll ans = N - right - CS.query(right, N);
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
