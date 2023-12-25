#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll K;
    cin >> K;

    ll ans = 0;
    for (ll a = 1; a*a*a <= K; a++) {
        if (K % a == 0) {
            ll X = K / a;
            for (ll b = a; b*b <= X; b++) {
                if (X % b == 0) ans++;
            }
        }
    }

    cout << ans << endl;
}
