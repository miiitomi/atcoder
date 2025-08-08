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
    vector<ll> A(N), B(N);
    ll ans = 0;
    for (ll &a: A) {
        cin >> a;
        a %= M;
        ans += a;
    }
    for (ll &b: B) {
        cin >> b;
        b %= M;
        ans += b;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for (ll b: B) {
        if (!A.empty() && A.back()+b >= M) {
            A.pop_back();
            ans -= M;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
