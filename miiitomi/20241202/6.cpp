// https://atcoder.jp/contests/abc271/tasks/abc271_g
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
    ll N, X, Y;
    cin >> N >> X >> Y;
    mint p = (mint)X * ((mint)100).inv();
    mint q = (mint)Y * ((mint)100).inv();
    string c;
    cin >> c;
    N--;

    vector<mint> v(24, 0);
    vector<vector<mint>> A(24, vector<mint>(24, 0));
    for (int x = 0; x < 24; x++) {
        for (int y = 0; y < 24; y++) {
            mint a = (c[y] == 'T')*p + (c[y]=='A')*q;
            mint b = 1;
            bool reached_y = false;
            for (int z = (x+1)%24; 1; z = (z+1)%24) {
                if (z == y) reached_y = true;
                if (c[z] == 'T') {
                    if (!reached_y) a *= (1 - p);
                    b *= (1 - p);
                } else {
                    if (!reached_y) a *= (1 - q);
                    b *= (1 - q);
                }
                if (z == x) break;
            }
            a *= (1 - b).inv();
            A[y][x] = a;
        }
    }
    mint r = 1;
    for (int x = 0; x < 24; x++) r *= (c[x]=='T')*(1 - p) + (c[x]=='A')*(1 - q);
    for (int x = 0; x < 24; x++) {
        mint s = 1;
        for (int z = 0; z < x; z++) s *= (c[z]=='T')*(1 - p) + (c[z]=='A')*(1 - q);
        v[x] = s * (1-r).inv() * ((c[x]=='T')*p + (c[x]=='A')*q);
    }


    A = matrix_pow(A, N);
    v = matrix_prod(A, v);
    mint ans = 0;
    for (int i = 0; i < 24; i++) if (c[i] == 'A') ans += v[i];
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
