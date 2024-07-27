#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());

    ll ans = N;
    ll tmp = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        tmp += A[i];
        cnt++;
        if (tmp > X) {
            ans = min(ans, cnt);
            break;
        }
    }
    tmp = 0; cnt = 0;
    for (int i = 0; i < N; i++) {
        tmp += B[i];
        cnt++;
        if (tmp > Y) {
            ans = min(ans, cnt);
            break;
        }
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
