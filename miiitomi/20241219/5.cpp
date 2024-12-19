// https://atcoder.jp/contests/abc102/tasks/arc100_b
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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    CumulativeSum<ll> S(A);
    ll ans = INF, a = 1, c = 3;
    for (ll b = 2; b <= N-2; b++) {
        while (a < b-1 && abs(S.query(0, a)-S.query(a,b)) > abs(S.query(0, a+1)-S.query(a+1, b))) a++;
        while (c < N-1 && abs(S.query(b, c) - S.query(c, N)) > abs(S.query(b, c+1) - S.query(c+1, N))) c++;
        ll ma = max(max(S.query(0, a), S.query(a, b)), max(S.query(b, c), S.query(c, N)));
        ll mi = min(min(S.query(0, a), S.query(a, b)), min(S.query(b, c), S.query(c, N)));
        ans = min(ans, ma-mi);
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
