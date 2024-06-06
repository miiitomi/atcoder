// https://atcoder.jp/contests/abc249/tasks/abc249_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), C((int)2e+5 + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        C[A[i]]++;
    }

    ll ans = 0;
    for (ll x = 1; x <= (ll)2e+5; x++) {
        if (C[x] == 0) continue;
        for (ll y = x; y <= (ll)2e+5; y += x) {
            ans += C[x] * C[y] * C[y/x];
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
