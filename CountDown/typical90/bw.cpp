#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    ll cnt = 0;
    for (ll x = 2; x*x <= N; x++) {
        while (N % x == 0) {
            cnt++;
            N /= x;
        }
    }
    if (N != 1) cnt++;

    ll ans = 0, s = 1;
    while (cnt > s) {
        s *= 2;
        ans++;
    }
    cout << ans << endl;
}
