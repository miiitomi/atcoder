#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, S, K;
    cin >> N >> S >> K;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll p, q;
        cin >> p >> q;
        ans += p*q;
    }

    if (ans >= S) {
        cout << ans << endl;
    } else {
        cout << ans + K << endl;
    }
}
