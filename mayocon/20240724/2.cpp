// https://atcoder.jp/contests/abc108/tasks/abc108_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> vector<vector<T>> matrix_prod(vector<vector<T>> &A, vector<vector<T>> &B) {
    int l = A.size();
    int m = B.size();
    int n = B[0].size();
    vector<vector<T>> V(l, vector<T>(n, 0));
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                V[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return V;
}
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
    vector<vector<ll>> V(4, {0, 0});
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) cin >> V[i][j];

    vector<vector<ll>> A = {
        {0, 1},
        {-1, 0}
    };

    vector<ll> v = {V[0][0]-V[1][0], V[0][1]-V[1][1]};
    v = matrix_prod(A, v);
    V[2] = {v[0] + V[1][0], v[1] + V[1][1]};

    v = {V[1][0] - V[2][0], V[1][1] - V[2][1]};
    v = matrix_prod(A, v);
    V[3] = {v[0] + V[2][0], v[1] + V[2][1]};

    cout << V[2][0] << " " << V[2][1] << " " << V[3][0] << " " << V[3][1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
