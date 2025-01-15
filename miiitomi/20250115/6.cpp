// https://atcoder.jp/contests/abc270/tasks/abc270_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint;

void solve() {
    ll P, A, B, S, G;
    cin >> P >> A >> B >> S >> G;

    if (A == 0) {
        if (S == G) cout << 0 << "\n";
        else if (B == G) cout << 1 << "\n";
        else cout << -1 << "\n";
        return;
    }

    mint::set_mod(P);
    mint c = 1, d = 0;
    ll M = (ll)round(sqrt(P+0.0)) + 1;
    for (ll k = 0; k < M; k++) {
        c = A*c;
        d = A*d + B;
    }
    mint p = (mint(A)).inv(), q = -B*(((mint)A).inv());
    map<ll, ll> mp;
    for (int j = 0; j <= M; j++) {
        if (!mp.contains(G)) {
            mp[G] = j;
        }
        G = (p*G + q).val();
    }

    for (int i = 0; i <= M; i++) {
        if (mp.contains(S)) {
            ll j = mp[S];
            cout << i*M + j << "\n";
            return;
        }
        S = (c*S + d).val();
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
