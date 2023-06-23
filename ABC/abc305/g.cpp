#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 998244353;

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

vector<ll> solve_n_small(int n, vector<string> &S) {
    ll n_all = (1LL << n);
    vector<ll> v(n_all, 1);

    for (int x = 0; x < n_all; x++) {
        string s = "";
        for (int i = n-1; i >= 0; i--) {
            if (x & (1 << i)) {
                s.push_back('b');
            } else {
                s.push_back('a');
            }
        }

        for (string c : S) {
            if ((int)s.size() < (int)c.size()) continue;
            for (int i = 0; i + (int)c.size() <= (int)s.size(); i++) {
                bool is_same = true;
                for (int a = 0; a < (int)c.size(); a++) {
                    if (s[i+a] != c[a]) {
                        is_same = false;
                        break;
                    }
                }
                if (is_same) {
                    v[x] = 0;
                    break;
                }
            }
            if (v[x] == 0) break;
        }
    }
    return v;
}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<string> S(M);
    for (int i = 0; i < M; i++) {
        cin >> S[i];
    }

    if (N <= 6) {
        vector<ll> v = solve_n_small(N, S);
        int ans = 0;
        for (int k = 0; k < (int)v.size(); k++) ans += v[k];
        cout << ans << endl;
        return 0;
    }

    vector<ll> v = solve_n_small(6, S);
    int k = (1 << 6);
    vector<vector<ll>> A(k, vector<ll>(k, 0));
    for (int x = 0; x < (1 << 6); x++) {
        int y = (x << 1) % (1 << 6);
        A[y][x] = (A[y][x] + 1) * v[y];
        y++;
        A[y][x] = (A[y][x] + 1) * v[y];
    }
    vector<vector<ll>> B = matrix_pow(A, N-6, MOD);
    vector<ll> q = matrix_prod(B, v, MOD);

    ll ans = 0;
    for (int i = 0; i < (int)q.size(); i++) {
        ans = (ans + q[i]) % MOD;
    }
    cout << ans << endl;
}
