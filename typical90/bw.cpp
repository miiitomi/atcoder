#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    ll x = 2LL;
    ll m = 1LL;
    while (x*x <= N) {
        if (N % x == 0) {
            m++;
            N /= x;
        } else {
            x++;
        }
    }
    ll ans = 0LL;
    while (m > 1LL) {
        m = (m / 2) + (m % 2);
        ans++;
    }
    cout << ans << endl;
}
