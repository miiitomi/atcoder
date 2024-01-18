// https://atcoder.jp/contests/abc296/tasks/abc296_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    if (N >= M) {
        cout << M << "\n";
        return 0;
    }

    ll ans = 1e+18;
    for (ll a = 1; a<= min((ll)2e+6, N); a++) {
        if (a*N < M) {
            continue;
        }
        ll b = (M-1+a)/a;
        ans = min(ans, a*b);
    }
    if (ans != (ll)1e+18) cout << ans << endl;
    else cout << -1 << endl;
}
