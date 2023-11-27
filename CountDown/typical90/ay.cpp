#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K, P;
    cin >> N >> K >> P;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll M = N/2;

    vector<vector<ll>> v(21);
    for (int s = 0; s < (1 << M); s++) {
        ll cnt = 0, price = 0;
        for (int i = 0; i < M; i++) {
            if (s & (1 << i)) {
                cnt++;
                price += A[i];
            }
        }
        v[cnt].push_back(price);
    }

    for (int i = 0; i <= 20; i++) sort(v[i].begin(), v[i].end());

    ll ans = 0;
    for (int s = 0; s < (1 << (N-M)); s++) {
        ll cnt = 0, price = 0;
        for (int i = 0; i < (N-M); i++) {
            if (s & (1 << i)) {
                cnt++;
                price += A[M+i];
            }
        }
        ll x = K - cnt;
        if (0 <= x && x <= 20) {
            ans += distance(v[x].begin(), lower_bound(v[x].begin(), v[x].end(), P - price + 1));
        }
    }
    cout << ans << endl;
}
