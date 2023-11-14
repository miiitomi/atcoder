// https://atcoder.jp/contests/abc199/tasks/abc199_f
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef mint ll;

vector<vector<ll>> matrix_prod(vector<vector<ll>> &A, vector<vector<ll>> &B) {
    int l = A.size();
    int m = B.size();
    int n = B[0].size();

    vector<vector<ll>> V(l, vector<ll>(n, 0LL));
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                V[i][j] = V[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    return V;
}

vector<ll> matrix_prod(vector<vector<ll>> &A, vector<ll> &B) {
    int l = A.size();
    int m = B.size();

    vector<ll> V(l, 0LL);
    for (int i = 0; i < l; i++) {
        for (int k = 0; k < m; k++) {
            V[i] = V[i] + A[i][k] * B[k];
        }
    }

    return V;
}

vector<vector<ll>> matrix_pow(vector<vector<ll>> &A, int p) {
    int a_size = A.size();

    if (p == 0) {
        vector<vector<ll>> V(a_size, vector<ll>(a_size, 0));
        for (int i = 0; i < a_size; i++) V[i][i] = 1;
        return V;
    }

    if (p == 1) {
        vector<vector<ll>> V = A;
        return V;
    }

    vector<vector<ll>> A_p_half = matrix_pow(A, p/2);
    vector<vector<ll>> V = matrix_prod(A_p_half, A_p_half);

    if (p % 2 == 0) return V;
    else return matrix_prod(V, A);
}


int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> x(M), y(M);
    for (int i = 0; i < M; i++) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }

    vector<mint> v(N, 0);
    for (int i = 0; i < N; i++) v[i] = A[i];
    vector<vector<mint>> P(N, vector<mint>(N, 0));
    for (int i = 0; i < N; i++) P[i][i] = 2*M;
    for (int i = 0; i < M; i++) {
        P[x[i]][x[i]] -= 1;
        P[x[i]][y[i]] += 1;
        P[y[i]][x[i]] += 1;
        P[y[i]][y[i]] -= 1;
    }
    mint p = ((mint)M*2).inv();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) P[i][j] *= p;
    }
    P = matrix_pow(P, K);
    v = matrix_prod(P, v);
    for (int i = 0; i < N; i++) {
        cout << v[i].val() << endl;
    }
}
