#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, x;
    cin >> N >> x;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    ll ans = 0;
    if (a[0] > x) {
        ans = a[0] - x;
        a[0] = x;
    }

    for (int i = 1; i < N; i++) {
        if (a[i-1] + a[i] > x) {
            ll s = a[i-1] + a[i] - x;
            ans += s;
            a[i] -= s;
        }
    }

    cout << ans << endl;
}
