// https://atcoder.jp/contests/abc204/tasks/abc204_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    ll H, W;
    cin >> H >> W;
    vector<ll> v((1 << H), 0);
    v[0] = 1;
    vector<vector<ll>> A((1 << H), vector<ll>(1 << H, 0));
    for (int s = 0; s < (1 << H); s++) {
        function<void(int, int, int)> f = [&](int i, int a, int b) -> void {
            if (i == H) {
                A[s][b]++;
                return;
            }
            if (a & (1 << i)) f(i+1, a, b);
            else {
                if (i+1 < H && !(a & (1 << (i+1)))) f(i+1, a + (1 << i) + (1 << (i+1)), b);
                f(i+1, a + (1 << i), b);
                f(i+1, a + (1 << i), b + (1 << i));
            }
        };
        f(0, s, 0);
    }

    A = matrix_pow(A, W-1, MOD);
    v = matrix_prod(A, v, MOD);

    ll ans = 0;
    for (int s = 0; s < (1 << H); s++) {
        ll cnt = 0;
        function<void(int, int)> f = [&](int i, int a) {
            if (i == H) {
                cnt++;
                return;
            }
            if (a & (1 << i)) f(i+1, a);
            else {
                f(i+1, a + (1 << i));
                if (i < H-1 && !(a & (1 << (i+1)))) f(i+1, a + (1 << i) + (1 << (i+1)));
            }
        };
        f(0, s);
        ans = (ans + cnt * v[s]) % MOD;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
