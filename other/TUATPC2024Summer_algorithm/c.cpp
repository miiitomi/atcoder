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
    string M;
    cin >> N >> M;
    ll m;
    if (M.size() <= 2) m = stoll(M);
    else {
        reverse(M.begin(), M.end());
        m = (ll)(M[0]-'0') + 10 * (ll)(M[1]-'0');
    }
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            ll ans =  ((m+i-1)*(m+j-1))%100;
            if (ans < 10) cout << 0 << ans;
            else cout << ans;
            if (j == N) cout << "\n";
            else cout << " ";
        }
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
