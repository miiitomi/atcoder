// https://atcoder.jp/contests/abc305/tasks/abc305_g
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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


void solve() {
    ll N, M;
    cin >> N >> M;
    vector<string> S(M);
    for (int i = 0; i < M; i++) cin >> S[i];

    if (N <= 6) {
        ll ans = 0;
        for (ll s = 0; s < (1LL << N); s++) {
            string T(N, 'a');
            for (int k = 0; k < N; k++) if (s & (1LL << k)) T[k] = 'b';
            bool is_ok = true;
            for (string ss : S) {
                for (int i = 0; i < N; i++) {
                    if (i + (int)ss.size() > (int)T.size()) break;
                    bool is_same = true;
                    for (int k = 0; k < (int)ss.size(); k++) {
                        if (ss[k] != T[i+k]) is_same = false;
                    }
                    if (is_same) {
                        is_ok = false;
                        break;
                    }
                }
                if (!is_ok) break;
            }
            if (is_ok) ans++;
        }
        cout << ans % MOD << "\n";
        return;
    }

    vector<ll> v((1LL << 6), 1);
    for (ll s = 0; s < (1LL << 6); s++) {
        string T(6, 'a');
        for (int i = 0; i < 6; i++) if (s & (1 << i)) T[i] = 'b';
        for (string ss : S) {
            for (int i = 0; i < 6; i++) {
                if (i + (int)ss.size() > 6) break;
                bool is_same = true;
                for (int k = 0; k < (int)ss.size(); k++) {
                    if (ss[k] != T[i+k]) {
                        is_same = false;
                        break;
                    }
                }
                if (is_same) {
                    v[s] = 0;
                    break;
                }
            }
            if (v[s] == 0) break;
        }
    }

    vector<vector<ll>> A((1 << 6), vector<ll>((1 << 6), 0));
    for (int i = 0; i < (1 << 6); i++) {
        if (v[i] == 0) continue;
        int j = i / 2;
        if (v[j] == 1) A[j][i] = 1;
        j += (1 << 5);
        if (v[j] == 1) A[j][i] = 1;
    }

    A = matrix_pow(A, N-6, MOD);
    v = matrix_prod(A, v, MOD);
    ll ans = 0;
    for (ll s = 0; s < (1LL << 6); s++) ans = (ans + v[s]) % MOD;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
