// https://atcoder.jp/contests/abc339/tasks/abc339_g
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll B = 1000;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), v;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        v.push_back(A[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) A[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), A[i]));

    ll K = (N + B-1) / B;
    vector<vector<ll>> S(v.size(), vector<ll>(K, 0));
    for (int i = 0; i < N; i++) S[A[i]][i / B] += v[A[i]];
    for (int a = 1; a < (int)v.size(); a++) {
        for (int k = 0; k < K; k++) {
            S[a][k] += S[a-1][k];
        }
    }

    ll Q;
    cin >> Q;
    ll ans = 0;
    while (Q--) {
        ll L, R, X;
        cin >> L >> R >> X;
        L = (L ^ ans) - 1;
        R = (R ^ ans);
        X = -1 + distance(v.begin(), lower_bound(v.begin(), v.end(), 1+(X ^ ans)));

        ans = 0;
        if (L % B != 0 && L/B != R/B) {
            while (L % B != 0) {
                if (A[L] <= X) ans += v[A[L]];
                L++;
            }
        }
        while (L/B != R/B) {
            if (X >= 0) ans += S[X][L/B];
            L += B;
        }
        while (L < R) {
            if (A[L] <= X) ans += v[A[L]];
            L++;
        }

        cout << ans << "\n";
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
