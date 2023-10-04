// https://atcoder.jp/contests/abc293/tasks/abc293_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

vector<ll> matrix_prod(vector<vector<ll>> &A, vector<ll> &B, ll mod) {
    int l = A.size();
    int m = B.size();

    vector<ll> V(l, 0LL);
    for (int i = 0; i < l; i++) {
        for (int k = 0; k < m; k++) {
            V[i] = (V[i] + ((A[i][k] % mod) * (B[k] % mod)) % mod) % mod;
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
    ll A, X, M;
    cin >> A >> X >> M;

    vector<vector<ll>> B{
        {A, 1},
        {0, 1}
    };
    vector<ll> c{1, 1};

    B = matrix_pow(B, X-1, M);
    vector<ll> a = matrix_prod(B, c, M);

    cout << a[0] << endl;
}
