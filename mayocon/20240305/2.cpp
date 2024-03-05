// https://atcoder.jp/contests/abc193/tasks/abc193_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    set<ll> S;
    for (ll a = 2; a*a <= N; a++) {
        ll x = a*a;
        while (x <= N) {
            S.insert(x);
            x *= a;
        }
    }
    cout << N - S.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
