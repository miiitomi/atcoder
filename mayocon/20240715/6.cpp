// https://atcoder.jp/contests/abc305/tasks/abc305_g
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


string make_str(ll a, ll k) {
    string ans = "";
    for (int i = 0; i < k; i++) {
        if (a & (1 << i)) ans.push_back('b');
        else ans.push_back('a');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool s_is_containing_t(string s, string t) {
    if ((int)s.size() < (int)t.size()) return false;
    for (int k = 0; k+(int)t.size() <= (int)s.size(); k++) {
        bool tmp = true;
        for (int i = 0; i < (int)t.size(); i++) {
            if (s[k+i] != t[i]) {
                tmp = false;
                break;
            }
        }
        if (tmp) return true;
    }
    return false;
}

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<string> S(M);
    for (int i = 0; i < M; i++) cin >> S[i];

    if (N <= 6) {
        ll ans = 0;
        for (ll s = 0; s < (1 << N); s++) {
            string a = make_str(s, N);
            bool is_ok = true;
            for (string &t : S) {
                if (s_is_containing_t(a, t)) {
                    is_ok = false;
                    break;
                }
            }
            if (is_ok) ans++;
        }
        cout << ans << "\n";
        return;
    }

    vector<mint> v((1LL << 6), 1);
    vector<vector<mint>> A((1LL << 6), vector<mint>((1LL << 6), 0));
    for (ll s = 0; s < (1 << 6); s++) {
        string a = make_str(s, 6);
        bool is_ok = true;
        for (string &t : S) {
            if (s_is_containing_t(a, t)) {
                is_ok = false;
                break;
            }
        }
        if (!is_ok) v[s] = 0;
    }
    for (ll s = 0; s < (1 << 6); s++) {
        if (v[s].val() == 0) continue;
        ll t = (s << 1) & ((1 << 6) - 1);
        if (v[t] != 0) A[t][s] = 1;
        t++;
        if (v[t] != 0) A[t][s] = 1;
    }

    A = matrix_pow(A, N-6);
    v = matrix_prod(A, v);
    mint ans = 0;
    for (ll s = 0; s < (1 << 6); s++) ans += v[s];
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
