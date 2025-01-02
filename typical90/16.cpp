// https://atcoder.jp/contests/typical90/tasks/typical90_p
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    ll ans = INF;
    for (ll a = 0; a <= 9999 && a*A <= N; a++) {
        for (ll b = 0; a+b <= 9999 && a*A+b*B <= N; b++) {
            if ((N - a*A - b*B) % C == 0) {
                ll c = (N - a*A - b*B) / C;
                ans = min(ans, a+b+c);
            }
        }
    }
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

