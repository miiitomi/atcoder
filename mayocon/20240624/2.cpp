// https://atcoder.jp/contests/abc326/tasks/abc326_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        ll x = A[i];
        auto iter = lower_bound(A.begin(), A.end(), x + M);
        ans = max(ans, (ll)distance(A.begin()+i, iter));
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
