// https://atcoder.jp/contests/abc189/tasks/abc189_e
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

void solve() {
    ll N;
    cin >> N;
    vector<vector<ll>> V(N, vector<ll>(3, 1));
    for (int i = 0; i < N; i++) cin >> V[i][0] >> V[i][1];

    ll M;
    cin >> M;
    vector<vector<vector<ll>>> A(M+1, vector<vector<ll>>{{1,0,0},{0,1,0},{0,0,1}});
    for (int i = 1; i <= M; i++) {
        ll t;
        cin >> t;
        vector<vector<ll>> B;
        if (t == 1) {
            B = {
                {0, 1, 0},
                {-1, 0, 0},
                {0, 0, 1}
            };
        } else if (t == 2) {
            B = {
                {0, -1, 0},
                {1, 0, 0},
                {0, 0, 1}
            };
        } else if (t == 3) {
            ll p;
            cin >> p;
            B = {
                {-1, 0, 2*p},
                {0, 1, 0},
                {0, 0, 1}
            };
        } else {
            ll p;
            cin >> p;
            B = {
                {1, 0, 0},
                {0, -1, 2*p},
                {0, 0, 1}
            };
        }

        A[i] = matrix_prod(B, A[i-1]);
    }

    ll Q;
    cin >> Q;
    while (Q--) {
        ll a, b;
        cin >> a >> b;
        b--;
        vector<ll> res = matrix_prod(A[a], V[b]);
        cout << res[0] << " " << res[1] << "\n";
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
