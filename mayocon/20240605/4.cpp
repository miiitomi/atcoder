// https://atcoder.jp/contests/abc178/tasks/abc178_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<ll> x(N), y(N);
    set<ll> U, V;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        U.insert(x[i] + y[i]);
        V.insert(x[i] - y[i]);
    }

    ll ans = max(*U.rbegin() - *U.begin(), *V.rbegin() - *V.begin());
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
