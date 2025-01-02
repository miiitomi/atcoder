// https://atcoder.jp/contests/typical90/tasks/typical90_j
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
    vector<vector<ll>> S(2, vector<ll>(N+1, 0));
    for (int i = 0; i < N; i++) {
        S[0][i+1] += S[0][i];
        S[1][i+1] += S[1][i];
        ll c, p;
        cin >> c >> p;
        S[c-1][i+1] += p;
    }
    ll Q;
    cin >> Q;
    while (Q--) {
        ll l, r;
        cin >> l >> r;
        l--;
        cout << S[0][r]-S[0][l] << " " << S[1][r] - S[1][l] << "\n";
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
