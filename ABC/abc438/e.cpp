#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<vector<pair<ll,ll>>> B(30, vector<pair<ll,ll>>(N, {0LL, 0LL}));
    for (ll i = 0; i < N; i++) {
        B[0][i] = {i+1LL, A[i]};
    }
    for (ll k = 1; k < 30; k++) {
        for (ll i = 0; i < N; i++) {
            B[k][i] = {B[k-1][i].first + B[k-1][B[k-1][i].second].first, B[k-1][B[k-1][i].second].second};
        }
    }
    while (Q--) {
        ll t, b, ans = 0;
        cin >> t >> b;
        b--;
        for (ll k = 0; k < 30; k++) {
            if ((t & (1LL << k))) {
                ans += B[k][b].first;
                b = B[k][b].second;
            }
        }
        cout << ans << "\n";
    }
}
