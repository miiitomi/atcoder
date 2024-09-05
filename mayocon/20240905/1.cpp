// https://atcoder.jp/contests/abc259/tasks/abc259_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> vector<T> matrix_prod(vector<vector<T>> &A, vector<T> &B) {
    int l = A.size();
    int m = B.size();
    vector<T> V(l, 0);
    for (int i = 0; i < l; i++) {
        for (int k = 0; k < m; k++) {
            V[i] += A[i][k] * B[k];
        }
    }
    return V;
}

void solve() {
    vector<double> v(2);
    double d;
    cin >> v[0] >> v[1] >> d;
    double theta = (d/360.0) * 2 * M_PI;
    vector<vector<double>> A = {
        {cos(theta), - sin(theta)},
        {sin(theta), cos(theta)}
    };
    v = matrix_prod(A, v);
    cout << v[0] << " " << v[1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
