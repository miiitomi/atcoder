// https://atcoder.jp/contests/abc084/tasks/abc084_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> C(N-1), S(N-1), F(N-1);
    for (int i = 0; i < N-1; i++) cin >> C[i] >> S[i] >> F[i];
    for (int i = 0; i <= N-1; i++) {
        int cur = i;
        ll t = 0;
        while (cur < N-1) {
            if (t < S[cur]) t = S[cur];
            if (t % F[cur] != 0) t += (F[cur] - (t%F[cur]));
            t += C[cur];
            cur++;
        }
        cout << t << "\n";
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
