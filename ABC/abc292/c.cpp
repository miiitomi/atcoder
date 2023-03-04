#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;

    vector<ll> X(N, 0);
    X[1] = 1;

    for (ll m = 2; m < N; m++) {
        for (ll x = 1; x*x <= m; x++) {
            if (m % x == 0) {
                if (x*x == m) X[m]++;
                else X[m] += 2;
            }
        }
    }

    ll ans = 0;
    for (ll a = 1; a <= N-1; a++) {
        ans += (X[a] * X[N-a]);
    }

    cout << ans << endl;
}
