// https://atcoder.jp/contests/abc199/tasks/abc199_f
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint1000000007;

template <typename T>
vector<vector<T>> matrix_prod(vector<vector<T>> &A, vector<vector<T>> &B) {
    int l = A.size();
    int m = B.size();
    int n = B[0].size();

    vector<vector<T>> V(l, vector<T>(n, 0LL));
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                V[i][j] = V[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    return V;
}

template <typename T>
vector<T> matrix_prod(vector<vector<T>> &A, vector<T> &B) {
    int l = A.size();
    int m = B.size();

    vector<T> V(l, 0LL);
    for (int i = 0; i < l; i++) {
        for (int k = 0; k < m; k++) {
            V[i] = V[i] + A[i][k] * B[k];
        }
    }

    return V;
}

template <typename T>
vector<vector<T>> matrix_pow(vector<vector<T>> &A, int p) {
    int a_size = A.size();

    if (p == 0) {
        vector<vector<T>> V(a_size, vector<T>(a_size, 0));
        for (int i = 0; i < a_size; i++) V[i][i] = 1;
        return V;
    }

    if (p == 1) {
        vector<vector<T>> V = A;
        return V;
    }

    vector<vector<T>> A_p_half = matrix_pow(A, p/2);
    vector<vector<T>> V = matrix_prod(A_p_half, A_p_half);

    if (p % 2 == 0) return V;
    else return matrix_prod(V, A);
}


void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<mint> A(N, 0);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[i] = a;
    }
    mint p = ((mint)(2*M)).inv();
    vector<vector<mint>> F(N, vector<mint>(N, 0));
    for (int i = 0; i < N; i++) F[i][i] = 1;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        F[x][x] -= p;
        F[x][y] += p;
        F[y][x] += p;
        F[y][y] -= p;
    }

    F = matrix_pow(F, K);
    A = matrix_prod(F, A);
    for (int i = 0; i < N; i++) {
        cout << A[i].val() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
