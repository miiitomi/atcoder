#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    vector<ll> K(M);
    vector<vector<bool>> A(M, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        cin >> K[i];
        for (int j = 0; j < K[i]; j++) {
            int a;
            cin >> a;
            a--;
            A[i][a] = true;
        }
    }

    ll L = 1;
    for (int k = 0; k < N; k++) L *= 3;

    ll ans = INF;

    for (int s = 0; s < L; s++) {
        int t = s;
        vector<int> cnt(M, 0);
        ll tmp = 0;
        for (int i = 0; i < N; i++) {
            int r = t % 3;
            t /= 3;
            tmp += r * C[i];
            for (int j = 0; j < M; j++) {
                cnt[j] += r * A[j][i];
            }
        }

        bool ok = true;
        for (int j = 0; j < M; j++) if (cnt[j] < 2) ok = false;
        if (ok) ans = min(ans, tmp);
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
