#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> V(3);
    for (int i = 0; i < 3; i++) cin >> V[i];
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());

    ll ans = 10000LL;
    ll K = min(N / V[0], 9999LL);
    for (int k = K; k >= 0; k--) {
        ll L = min((N - k*V[0]) / V[1], 9999LL);
        for (int l = L; l >= 0; l--) {
            ll n = N - k*V[0] - l*V[1];
            if (n % V[2] == 0) {
                ans = min(ans, k + l + (n / V[2]));
            }
        }
    }
    cout << ans << endl;
}
