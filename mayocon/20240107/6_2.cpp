// https://atcoder.jp/contests/abc193/tasks/abc193_e
#include <bits/stdc++.h>
#include <atcoder/math>
using namespace std;
using namespace atcoder;
typedef long long ll;
const ll INF = 9e+18;

void solve() {
    ll X, Y, P, Q;
    cin >> X >> Y >> P >> Q;
    ll ans = INF;
    for (ll y = 0; y < Y; y++) {
        for (ll q = 0; q < Q; q++) {
            vector<ll> r = {X+y, P+q}, m = {2*(X+Y), P+Q};
            pair<ll, ll> p = crt(r, m);
            if (p.second > 0) {
                ans = min(ans, p.first);
            }
        }
    }

    if (ans < INF) cout << ans << endl;
    else cout << "infinity" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
