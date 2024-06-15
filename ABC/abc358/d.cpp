#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N, M;
    cin >> N >> M;
    multiset<ll> A;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        A.insert(a);
    }
    ll ans = 0;
    for (int i = 0; i < M; i++) {
        ll b;
        cin >> b;
        auto iter = A.lower_bound(b);
        if (iter == A.end()) {
            cout << -1 << endl;
            return;
        }
        ans += *iter;
        A.erase(iter);
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
