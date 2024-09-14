// https://atcoder.jp/contests/abc230/tasks/abc230_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, A, B;
    cin >> N >> A >> B;

    ll P, Q, R, S;
    cin >> P >> Q >> R >> S;

    for (ll i = P; i <= Q; i++) {
        for (ll j = R; j <= S; j++) {
            bool is_black = false;
            ll k = i - A;
            if (max(1-A, 1-B) <= k && k <= min(N-A, N-B) && j == B+k) is_black = true;
            if (max(1-A, B-N) <= k && k <= min(N-A, B-1) && j == B-k) is_black = true;
            if (is_black) cout << "#";
            else cout << ".";
        }
        cout << "\n";
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
