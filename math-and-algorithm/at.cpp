#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000000;

vector<vector<ll>> matrix_prod(vector<vector<ll>> &A, vector<vector<ll>> &B, ll mod) {
    int l = A.size();
    int m = B.size();
    int n = B[0].size();

    vector<vector<ll>> V(l, vector<ll>(n, 0LL));
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                V[i][j] = (V[i][j] + ((A[i][k] % mod) * (B[k][j] % mod)) % mod) % mod;
            }
        }
    }

    return V;
}

vector<vector<ll>> matrix_pow(vector<vector<ll>> &A, ll p, ll mod) {
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

    vector<vector<ll>> A_p_half = matrix_pow(A, p/2, mod);
    vector<vector<ll>> V = matrix_prod(A_p_half, A_p_half, mod);

    if (p % 2 == 0) return V;
    else return matrix_prod(V, A, mod);
}

int main() {
    ll N;
    cin >> N;

    vector<vector<ll>> A(2, vector<ll>(2, 1));
    A[1][1] = 0;

    vector<vector<ll>> B = matrix_pow(A, N-1, MOD);

    vector<vector<ll>> x(2, vector<ll>(1, 1));
    x[1][0] = 0;

    vector<vector<ll>> v = matrix_prod(B, x, MOD);

    cout << v[0][0] << endl;
}
