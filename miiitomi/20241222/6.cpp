// https://atcoder.jp/contests/abc295/tasks/abc295_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> F(2001, 1);
vector<vector<mint>> C(2001, vector<mint>(2001, 0));

template<typename T> T mod_pow(T a, ll n) {
    if (n == 0) return 1;
    T res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res * a;
    return res * res;
}

void solve() {
    int N, M, K, Z = 0;
    cin >> N >> M >> K;
    vector<int> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a == 0) Z++;
        else A.push_back(a);
    }
    sort(A.begin(), A.end());
    vector<mint> P(M+1, 0);
    mint q = ((mint)M).inv();
    for (int m = 1; m <= M; m++) {
        int cnt = distance(A.begin(), lower_bound(A.begin(), A.end(), m+1));
        if (cnt >= K) {
            P[m] = 1;
            continue;
        }
        int r = K - cnt;
        for (int k = r; k <= Z; k++) {
            P[m] += C[Z][k] * mod_pow(q*m, k) * mod_pow(q*(M-m), Z-k);
        }
    }
    mint ans = 0;
    for (int k = M; k >= 1; k--) ans += k*(P[k]-P[k-1]);
    cout << ans.val() << endl;
}

int main() {
    for (int x = 1; x <= 2000; x++) F[x] = F[x-1]*x;
    for (int n = 0; n <= 2000; n++) {
        for (int r = 0; r <= n; r++) {
            C[n][r] = F[n] / (F[n-r]*F[r]);
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
