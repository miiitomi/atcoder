// https://atcoder.jp/contests/abc246/tasks/abc246_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, K, X;
    cin >> N >> K >> X;
    priority_queue<ll> Q;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        ll s = min(a / X, K);
        K -= s;
        a -= s*X;
        Q.push(a);
    }

    if (K > Q.size()) {
        cout << 0 << endl;
        return;
    }

    while (K > 0 && !Q.empty()) {
        ll a = Q.top();
        Q.pop();
        K--;
        if (a <= X) continue;
        Q.push(a - X);
    }

    ll ans = 0;
    while (!Q.empty()) {
        ll a = Q.top();
        Q.pop();
        ans += a;
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
