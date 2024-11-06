// https://atcoder.jp/contests/abc104/tasks/abc104_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> T mod_pow(T a, ll n) {
    if (n == 0) return 1;
    T res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res * a;
    return res * res;
}

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
    vector<ll> a(N, 0), b(N, 0), c(N, 0), x(N, 0);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'A') a[i]++;
        else if (S[i] == 'B') b[i]++;
        else if (S[i] == 'C') c[i]++;
        else x[i]++;
    }
    CumulativeSum<ll> A(a), B(b), C(c), X(x);
    mint ans = 0, zero = mod_pow((mint)3, X.query(0, N)), one = mod_pow((mint)3, X.query(0, N)-1), two = mod_pow((mint)3, X.query(0, N)-2), three = mod_pow((mint)3, X.query(0, N)-3);
    for (int i = 0; i < N; i++) {
        ll left_a = A.query(0, i), left_x = X.query(0, i), right_x = X.query(i+1, N), right_c = C.query(i+1, N);
        if (S[i] == 'B') {
            ans += zero * left_a * right_c;
            ans += one * left_x * right_c;
            ans += one * left_a * right_x;
            ans += two * left_x * right_x;
        } else if (S[i] == '?') {
            ans += one * left_a * right_c;
            ans += two * left_x * right_c;
            ans += two * left_a * right_x;
            ans += three * left_x * right_x;
        }
    }
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
