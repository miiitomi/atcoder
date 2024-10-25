// https://atcoder.jp/contests/abc058/tasks/arc071_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = (ll)1e+9 + 7;

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

mint f(ll N) {
    vector<mint> X(N);
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        x = (x + (ll)1e+9) % MOD;
        X[i] = (mint)x;
    }
    CumulativeSum<mint> cs(X);
    mint ans = 0;
    for (int i = 1; i < N; i++) {
        ans += i*X[i] - cs.query(0, i);
    }
    return ans;
}

void solve() {
    ll N, M;
    cin >> N >> M;
    mint ans = f(N);
    ans *= f(M);
    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
