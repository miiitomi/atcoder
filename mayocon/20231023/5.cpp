// https://atcoder.jp/contests/abc186/tasks/abc186_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
typedef long long ll;
using mint = modint;

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

void solve() {
    ll N, S, K;
    cin >> N >> S >> K;

    ll g = GCD(N, K);
    while (g != 1LL) {
        if (S % g != 0) {
            cout << -1 << endl;
            return;
        }
        N /= g;
        K /= g;
        S /= g;
        g = GCD(N, K);
    }

    mint::set_mod(N);
    cout << ((mint)(N-S) * ((mint)K).inv()).val() << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
