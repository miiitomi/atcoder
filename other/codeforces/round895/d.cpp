#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

ll lcm(ll a, ll b) {
    ll d = gcd(a, b);
    return a / d * b;
}

void solve() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    ll Z = lcm(X, Y);

    ll num_z = N / Z;
    ll num_x = N / X - num_z;
    ll num_y = N / Y - num_z;

    ll ans = num_x * (2 * N - (num_x - 1)) / 2;
    ans -= num_y * (num_y + 1) / 2;

    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
