// https://atcoder.jp/contests/abc134/tasks/abc134_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    multiset<ll> S;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll a = A[i];
        auto iter = S.lower_bound(a);
        if (iter == S.begin()) {
            ans++;
            S.insert(a);
        } else {
            iter--;
            S.erase(iter);
            S.insert(a);
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
