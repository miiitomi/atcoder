// https://atcoder.jp/contests/abc199/tasks/abc199_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

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
template<typename T> vector<vector<T>> matrix_pow(vector<vector<T>> &A, ll p) {
    if (p == 1) return A;
    int a_size = A.size();
    if (p == 0) {
        vector<vector<T>> V(a_size, vector<T>(a_size, 0));
        for (int i = 0; i < a_size; i++) V[i][i] = 1;
        return V;
    }
    vector<vector<T>> A_p_half = matrix_pow(A, p/2);
    vector<vector<T>> V = matrix_prod(A_p_half, A_p_half);
    if (p % 2 == 0) return V;
    return matrix_prod(V, A);
}

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<mint> v(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v[i] = a;
    }
    vector<int> X(M), Y(M);
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        cin >> X[i] >> Y[i];
        X[i]--; Y[i]--;
        G[X[i]].push_back(Y[i]);
        G[Y[i]].push_back(X[i]);
    }
    vector<vector<mint>> A(N, vector<mint>(N, 0));
    mint p = ((mint)M).inv();
    mint q = p/2;
    for (int i = 0; i < N; i++) {
        A[i][i] += p*(M-(int)G[i].size());
        for (int j : G[i]) {
            A[i][i] += q;
            A[i][j] += q;
        }
    }
    A = matrix_pow(A, K);
    v = matrix_prod(A, v);
    for (int i = 0; i < N; i++) cout << v[i].val() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
